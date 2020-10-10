/*
Design a base class shape with two double type values and member functions to input the data and compute_area() 
for calculating area of shape. Derive two classes’ triangle and rectangle. Make compute_area() as abstract function 
and redefine this function in the derived class to suit their requirements. Write a program that accepts dimensions 
of triangle/rectangle and display calculated area. Implement dynamic binding for given case study.
*/

import java.util.Scanner;

abstract class shape{
    abstract void compute_area();
}

class rectangle extends shape {
    
    void compute_area(){
        Scanner scan = new Scanner(System.in);
        System.out.println("Enter value of length of rectangle: ");
        double length = scan.nextDouble();
        System.out.println("Enter value of breadth of rectangle: ");
        double breadth = scan.nextDouble();
        double area=length * breadth;
        System.out.println("area of rectangle is "+area);
    }
}

class triangle extends shape {
    
    void compute_area(){
        Scanner scan1 = new Scanner(System.in);
        System.out.println("Enter value of base length of triangle: ");
        double base_length = scan1.nextDouble();
        System.out.println("Enter value of height of triangle: ");
        double height = scan1.nextDouble();
        double area=(base_length * height)/2;
        System.out.println("area of triangle is "+area);
    }
}

class circle extends shape {
    
    void compute_area(){
        Scanner scan = new Scanner(System.in);
        System.out.println("Enter value of radius of circle: ");
        double radius = scan.nextDouble();
        double area=(22/7)*(radius * radius);
        System.out.println("area of circle is "+area);
    }
}

public class areaassignment {
    public static void main(String[] args) {
            shape obj= new rectangle();
            obj.compute_area(); 
            System.out.println("==================");
            obj= new triangle();
            obj.compute_area(); 
            System.out.println("==================");
            obj= new circle();
            obj.compute_area(); 
            System.out.println("==================");

    }

}
