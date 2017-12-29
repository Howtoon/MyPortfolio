/**
Name:William Tennis
Date: 01/20/2016
Project 2
*/

public class Car extends Vehicle
{
   private int doorCount;
   
   public Car(int count)
   {
      this.setDoorCount(count);
   }
   
   public Car(String color, int count)
   {
      this.setDoorCount(count);
      super.setColor(color);
   }
   
   public void setDoorCount(int count)
   {
      doorCount=count;
      return;
   }
   
   public int getDoorCount()
   {
      return doorCount;
   }
   
   public void info()
   {
      super.info();
      System.out.println("Door Count: "+this.getDoorCount());
      return;
   }
}