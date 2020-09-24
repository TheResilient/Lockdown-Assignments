

//Emp_name, Emp_id, Address, Mail_id, and Mobile_no 

import java.util.Scanner;

class Employee
{
    int mobile, id;
    String name, address, mail;
    double pay;
    Scanner get = new Scanner(System.in);
    Employee()
    {
        System.out.println("Enter Name of the Employee:");
        name = get.nextLine();
        System.out.println("Enter mail id of employee: ");
        mail=get.nextLine();
        System.out.println("Enter adress id of employee: ");
        address=get.nextLine();
        System.out.println("Enter id of the Employee:");
        id = get.nextInt();
        System.out.println("Enter Pay:");
        pay = get.nextInt();

    }
}

//Programmer, Team Lead, Assistant Project Manager and Project Manager

//97% of BP as DA, 10 % of BP as HRA, 12% of BP as PF, 0.1% of BP for staff club fund.

class Programmer extends Employee
{
  
  public void printpay1()
  {
    double da=0.97*pay;
    double hra=.1*pay;
    double pf=.12*pay;
    double gp=pay + da + hra;
    double np=gp-pf;
    System.out.print("Name of Employee: ");    
    System.out.println(name);
    System.out.print("Net Pay: ");    
    System.out.println(np);
    System.out.print("and Gross Pay: ");    
    System.out.println(np);
  }
}
class AssistantProjectManager extends Employee
{
  
  public void printpay1()
  {
    double da=0.97*pay;
    double hra=.1*pay;
    double pf=.12*pay;
    double gp=pay + da + hra;
    double np=gp-pf;
    System.out.print("Name of Employee: ");    
    System.out.println(name);
    System.out.print("Net Pay: ");    
    System.out.println(np);
    System.out.print("and Gross Pay is: ");    
    System.out.println(np);
  }
}


class ProjectManager extends Employee
{
  

  public void printpay1()
  {
    double da=0.97*pay;
    double hra=.1*pay;
    double pf=.12*pay;
    double gp=pay + da + hra;
    double np=gp-pf;
    System.out.print("Name of Employee: ");    
    System.out.println(name);
    System.out.print("Net Pay: ");    
    System.out.println(np);
    System.out.print("and Gross Pay: ");    
    System.out.println(np);
  }
}


class TeamLead extends Employee
{
  public void printpay1()
  {
    double da=0.97*pay;
    double hra=.1*pay;
    double pf=.12*pay;
    double gp=pay + da + hra;
    double np=gp-pf;
    System.out.print("Name of Employee: ");    
    System.out.println(name);
    System.out.print("Net Pay: ");    
    System.out.println(np);
    System.out.print("and Gross Pay: ");    
    System.out.println(np);
  }
}

public class Main
{
  public static void main (String args[])
  {

    Programmer nameofemployee= new Programmer();
    

  }
}
