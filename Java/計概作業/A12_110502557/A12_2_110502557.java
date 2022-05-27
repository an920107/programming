package A12_110502557;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.text.SimpleDateFormat;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.Date;
import java.util.List;
import java.util.Set;
import java.util.TreeSet;

import org.jsoup.Jsoup;
import org.jsoup.nodes.Document;
import org.jsoup.nodes.Element;

public class A12_2_110502557 {
    public static void main(String[] args) throws Exception {

        final SimpleDateFormat DATE_FORMAT = new SimpleDateFormat("yyyy-MM-dd");

        Set<Title> titles = new TreeSet<>(new TitleComparator());
        Document document = Jsoup.connect("https://www.csie.ncu.edu.tw/").get();
        
        for (Element block : document.select("div[class=\"announcement-scope\"]")) {
            for (Element link : block.select("a[class=\"link\"]")) {
                String text = link.text();
                Date date = DATE_FORMAT.parse(text.substring(text.length() - 11));
                text = text.substring(0, text.length() - 11);
                titles.add(new Title(date, text));
            }
        }

        List<Title> reversedTitles = new ArrayList<>(titles);
        Collections.reverse(reversedTitles);
        try (BufferedWriter writer = new BufferedWriter(new FileWriter(new File("A12_2_110502557.txt")))) {
            for (Title title : reversedTitles) {
                // writer.write(String.format("%s %s\n", DATE_FORMAT.format(title.getDate()), title.getText()));
                System.out.printf("%s %s\n", DATE_FORMAT.format(title.getDate()), title.getText());
            }
        }
    }
}



class Title {

    private Date date;    
    private String text;

    public Title (Date date, String text) throws Exception {
        this.date = date;
        this.text = text;
    }

    public Date getDate() { return date; }
    public String getText() { return text; }
}

class TitleComparator implements Comparator<Title> {

    @Override
    public int compare(Title o1, Title o2) {
        if (o1.getDate().before(o2.getDate()))
            return -1;
        else if (o1.getDate().after(o2.getDate()))
            return 1;
        else return o1.getText().compareTo(o2.getText());
    }
}


