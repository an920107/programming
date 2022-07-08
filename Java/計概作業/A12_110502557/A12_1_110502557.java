package A12_110502557;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;

import org.jsoup.Jsoup;
import org.jsoup.nodes.Document;

public class A12_1_110502557 {
    public static void main(String[] args) throws Exception {
        Document document = Jsoup.connect("https://www.csie.ncu.edu.tw/").get();
        try (BufferedWriter writer = new BufferedWriter(new FileWriter(new File("A12_1_110502557.txt")))) {
            writer.write(document.outerHtml());
        }
    }
}
