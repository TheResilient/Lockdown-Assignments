import java.util.Scanner;

class Publication{
    public int copies;
    public int price;
    public String title;
    static int soldcopies;
    public void SaleCopy(){
        System.out.println("==========================Total sold data==========================");
        System.out.println("Total Sold copies combine of books and magazines are "+soldcopies);
    }
    
};

class Book extends Publication{
    private String author;
    private int printcopies;
    private static int soldbooks;
    Scanner get= new Scanner(System.in);
    Book(){
        System.out.println("==========================Book Input data==========================");
        System.out.print("enter author name: ");
        author=get.nextLine();
        System.out.println("==========================");
        System.out.print("enter price of book: ");
        price=get.nextInt();
        System.out.println("==========================");
        System.out.print("enter no of copies to be printed: ");
        printcopies=get.nextInt();
        soldbooks=soldbooks+printcopies;
        soldcopies=soldcopies+printcopies;
    }
    public void SaleCopy(){
        System.out.println();
        System.out.println("==========================Book output data==========================");
        System.out.println("name of the author is "+author);
        
        System.out.println("==========================");
        System.out.println("number of copies to be printed are "+printcopies);
        
        System.out.println("==========================");
        System.out.println("price of ordered books are "+(printcopies*price));
        
        System.out.println("==========================");
        System.out.println("total books sold till date are "+soldbooks);
    }
};

class Magazine extends Publication{
    private int orderquantity;
    private String currentissue;
    private String receiveissue;
    private static int soldmagazines;
    Scanner get= new Scanner(System.in);
    Magazine(){

        System.out.println("==========================Magazine Input data==========================");
        System.out.print("enter current issue: ");
        currentissue=get.nextLine();
        
        System.out.println("==========================");
        System.out.print("enter receive issue: ");
        receiveissue=get.nextLine();
        
        System.out.println("==========================");
        System.out.print("enter price of receive issue: ");
        price=get.nextInt();

        System.out.println("==========================");
        System.out.print("enter order quantity: ");
        orderquantity=get.nextInt();

        soldmagazines=soldmagazines+orderquantity;
        soldcopies=soldcopies+orderquantity;
    }
    public void SaleCopy(){
        System.out.println();
        System.out.println("==========================Magazine output data==========================");
        System.out.print("name of current issue is ");
        System.out.println(currentissue);
        
        System.out.println("==========================");
        System.out.print("name of received issue is ");
        System.out.println(receiveissue);
        
        System.out.println("==========================");
        System.out.print("number of ordered quantity is ");
        System.out.println(orderquantity);
        
        System.out.println("==========================");
        System.out.print("price of ordered books are ");
        System.out.println(orderquantity*price);

        System.out.println("==========================");
        System.out.println("total magazines sold till date are "+soldmagazines);
    }
};



public class polymorphism
{
	public static void main(String[] args) {
        
        Publication obj1;
		obj1= new Book();
        obj1.SaleCopy();

		Publication obj2;
		obj2= new Book();
        obj2.SaleCopy();
        
        Publication obj3;
        obj3=new Magazine();
        obj3.SaleCopy();

        Publication obj4;
        obj4=new Magazine();
        obj4.SaleCopy();

        Publication t=new Publication();
        t.SaleCopy();
	}
}
