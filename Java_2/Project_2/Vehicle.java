/**
Name:William Tennis
Date: 01/20/2016
Project 2
*/

public class Vehicle{
   private String color;
   
   public Vehicle()
   {
      this("Blue default color");
   }
   
   public Vehicle(String a)
   {
      this.setColor(a);
   }
   
   public String getColor()
   {
      return color;
   }
   
   public void setColor(String a)
   {
      color=a;
      return;
   }
   public void info()
   {
      System.out.println("Color: "+this.getColor());
      return;
   }
}