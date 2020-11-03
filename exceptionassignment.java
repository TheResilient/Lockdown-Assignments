import java.util.Scanner;
public class exceptionassignment {
    public static void main(String[] args) {        
        String arr[]= new String[2];
        try{
            int i=0;
            boolean j= true;
            while(j){
                Scanner s= new Scanner(System.in);
                
                System.out.println("enter number: ");
                String in=s.nextLine();
                arr[i]= in;
                System.out.println("do you want to enter one more number(1/0): \n");
                int k= s.nextInt();
                if(k==0){
                    j=false;
                }
                i++;
            }
            int a= Integer.parseInt(arr[0]);
            int b= Integer.parseInt(arr[1]);
            System.out.println("Division is: ");
            System.out.println(a/b);
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
