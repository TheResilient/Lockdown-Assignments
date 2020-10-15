/*
Design and develop a context for given case study and implement an interface for Vehicles 
Consider the example of vehicles like bicycle, car, and bike. All Vehicles have common 
functionalities such as Gear Change, Speed up and apply breaks .Make an interface and 
put all these common functionalities. Bicycle, Bike, Car classes should be implemented 
for all these functionalities in their own class in their own way.
*/

interface gear{
    void gearchange();
    void speedup();
    void applybrakes();
}

class Bicycle implements gear{
    public void gearchange(){System.out.println("changing gears of bicycle !\n");}
    public void speedup(){System.out.println("speeding up bicycle !\n");}
    public void applybrakes(){System.out.println("applying brakes of bicycle !\n");}
}
class Car implements gear{
    public void gearchange(){System.out.println("changing gears of Car !\n");}
    public void speedup(){System.out.println("speeding up Car !\n");}
    public void applybrakes(){System.out.println("applying brakes of Car !\n");}
}
class Bike implements gear{
    public void gearchange(){System.out.println("changing gears of Bike !\n");}
    public void speedup(){System.out.println("speeding up Bike !\n");}
    public void applybrakes(){System.out.println("applying brakes of Bike !\n");}
}

public class vehicle{
    public static void main(String[] args) {
        gear g=new Car();
        g.gearchange();
        g.applybrakes();
        g.speedup();
    }
}
