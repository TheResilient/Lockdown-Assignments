import java.util.Scanner;
public class exceptionassignment {
    public static void main(String[] args) {        
        Scanner s= new Scanner(System.in);
        String arr[]= new String[2];
        try{
            int i=0;
            while(i<2){
                System.out.println("enter number or x to break: ");
                String j= s.nextLine();
                if(j=="x") break;
                arr[i]=j;
                i++;
            }
            int a= Integer.parseInt(arr[0]);
            int b= Integer.parseInt(arr[1]);
            int j=a/b;
            System.out.println("\nDivision is: ");
            System.out.println(j);
        }
        catch(ArrayIndexOutOfBoundsException e) {
            System.out.println("Array is full so you cannot add more values!!\n");
        }

        catch(ArithmeticException e){
            System.out.println("Arithmetic Exception occured due to invalid input!!\n");
        }
        catch(NumberFormatException e){
            System.out.println("Invalid input you have to enter integer!!\n");
        }
        finally{System.out.println("end of the code\n");}        

    }
}
