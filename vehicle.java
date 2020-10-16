/*
Design and develop a context for given case study and implement an interface for Vehicles 
Consider the example of vehicles like bicycle, car, and bike. All Vehicles have common 
functionalities such as Gear Change, Speed up and apply breaks .Make an interface and 
put all these common functionalities. Bicycle, Bike, Car classes should be implemented 
for all these functionalities in their own class in their own way.
*/

interface gear{
    void gearchange(int i);
    void speedup(int i);
    void applybrakes();
}

class Bicycle implements gear{
    public void gearchange(int i){System.out.println("changing gear to "+i+" of bicycle !\n");}
    public void speedup(int j){System.out.println("speeding up bicycle to "+j+"!\n");}
    public void applybrakes(){System.out.println("applying brakes of bicycle !\n");}
}
class Car implements gear{
    public void gearchange(int i){System.out.println("changing gear to "+i+" of car !\n");}
    public void speedup(int j){System.out.println("speeding up car to "+j+"!\n");}
    public void applybrakes(){System.out.println("applying brakes of Car !\n");}
}
class Bike implements gear{
    public void gearchange(int i){System.out.println("changing gear to "+i+" of bike !\n");}
    public void speedup(int j){System.out.println("speeding up bike to "+j+"!\n");}
    public void applybrakes(){System.out.println("applying brakes of Bike !\n");}
}

public class Main{
    public static void main(String[] args) {
        gear g=new Car();
        g.gearchange(3);
        g.applybrakes();
        g.speedup(34);
    }
}
