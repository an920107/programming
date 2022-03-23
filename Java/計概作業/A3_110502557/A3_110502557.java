/**
 * Assignment 03
 * Student Number: 110502557
 * Course: 2022-CE1002
 */

package A3_110502557;

import java.util.Vector;

public class A3_110502557 {
    //Book1 information
    static private String N1="book1";
    static private String iSBN1="978-3-14-131238-2";
    static Vector<String> CONTENT1= new Vector<>();

    //Book2 information
    static private String N2="book2";
    static private String iSBN2="278-33-4-133238-0";
    static Vector<String> CONTENT2= new Vector<>();

    public static void main(String[] args)
    {
        CONTENT1.add("book1p1");
        CONTENT1.add("book1p2");
        CONTENT1.add("book1p3");

        CONTENT2.add("book2p1");
        CONTENT2.add("book2p2");

        Book myBook1 = new Book(N1,iSBN1,CONTENT1);
        Book myBook2 = new Book(N2,iSBN2,CONTENT2);

        //Testing
        System.out.println(myBook1.getName()+" "+myBook1.getISBN());
        System.out.println(myBook2.getName()+" "+myBook2.getISBN());
        System.out.println(myBook1.getContent(0)+" "+myBook1.getContent(3));
        myBook1.addPage("book1p4");
        System.out.println(myBook1.getContent(0)+" "+myBook1.getContent(3));

        BookShelf myBookShelf = new BookShelf();
        myBookShelf.addBook(myBook1);
        myBookShelf.addBook(myBook1);
        myBookShelf.addBook(myBook2);
        myBookShelf.showBookShelf();
    }
}

class Book {
    private String name;
    private String iSBN;
    private Vector<String> content;

    public Book(String name, String iSBN, Vector<String> content) {
        this.name = name;
        this.iSBN = iSBN;
        this.content = content;
    }

    public String getName() {
        return name;
    }

    public String getISBN() {
        return iSBN;
    }

    public String getContent(int page) {
        if (page < content.size())
            return content.get(page);
        return "ERROR";
    }

    public void addPage(String sentence) {
        content.add(sentence);
    }
}

class BookShelf {
    private Vector<Book> shelf = new Vector<>();

    public BookShelf() {}

    public void addBook(Book myBook) {
        shelf.add(myBook);
    }

    public void showBookShelf() {
        final int len = shelf.size();
        for (int i = 0; i < len; i ++) {
            Book book = shelf.get(i);
            System.out.println(i + " " + book.getName() + " " + book.getISBN());
        }
    }
}
