//================================================================
/*
import java.util.Scanner;
public class j {
   public static void main(String[] args){
      int year;
      System.out.println("Enter an Year :: ");
      Scanner sc = new Scanner(System.in);
      year = sc.nextInt();
	  sc.close();
      if (((year % 4 == 0) && (year % 100!= 0)) || (year%400 == 0))
         System.out.println("Specified year is a leap year");
      else
         System.out.println("Specified year is not a leap year");
   }
}

//==================================================================

import java.util.Scanner;
public class j
{
   public static void main(String[ ] arg)
   {
	boolean isVowel=false;
	Scanner scanner=new Scanner(System.in);
	System.out.println("Enter a character : ");
	char ch=scanner.next().charAt(0); 
	scanner.close();
	switch(ch)
	{
	   case 'a' :
	   case 'e' :
       case 'i' :
	   case 'o' :
	   case 'u' :
	   case 'A' :
	   case 'E' :
	   case 'I' :
	   case 'O' :
	   case 'U' : isVowel = true;
	}
	if(isVowel == true) {
	   System.out.println(ch+" is  a Vowel");
	}
	else {
	   if((ch>='a'&&ch<='z')||(ch>='A'&&ch<='Z'))
		System.out.println(ch+" is a Consonant");
	   else
		System.out.println("Input is not an alphabet");		
        }
   }
}
*/
//===============================================================
/*
import java.util.Scanner;

public class j {
    public static void main(String[] args) {
		Scanner scanner=new Scanner(System.in);
		System.out.println("Enter 1st number:");
		int num1=scanner.nextInt();
		System.out.println("Enter 2nd number:");
        int num2=scanner.nextInt();
        int quotient = num1 / num2;
        int remainder = num1 % num2;
        System.out.println("Quotient is: " + quotient);
        System.out.println("Remainder is: " + remainder);
    }
}

//=================================================================
*/

/*
import java.util.Scanner;

class j {

	static void countEachChar(String str) {
		int counter[] = new int[256];
		int len = str.length();

		for (int i = 0; i < len; i++)
			counter[str.charAt(i)]++;

		char array[] = new char[str.length()];
		for (int i = 0; i < len; i++) {
			array[i] = str.charAt(i);
			int flag = 0;
			for (int j = 0; j <= i; j++) {
				if (str.charAt(i) == array[j])
					flag++;
			}

			if (flag == 1)
				System.out.println("Occurrence of char " + str.charAt(i) + " in the String is: " + counter[str.charAt(i)]);
		}
	}

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		System.out.println("Enter string:");
		String str = scanner.nextLine();
		scanner.close();
		countEachChar(str);
	}
}

*/
//=====================================================================================
/*
import java.util.Scanner;
public class j
{
	public static void main(String[] args) {
		Scanner scanner= new Scanner(System.in);
		System.out.println("Total numbers to be entered: ");
		int n=scanner.nextInt();
		int total=0;
		for(int i=0; i<n; i++){
			System.out.println("Enter number or 0 to exit: ");
			int m=scanner.nextInt();
			if(m==0){
				break;
			}
			else total=total+m;
		}
		float avg=total/n;
		System.out.println("Average is: ");
		System.out.println(avg);
	}
}

*/