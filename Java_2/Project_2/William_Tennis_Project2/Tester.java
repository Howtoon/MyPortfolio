/**
Name:William Tennis
Date: 01/20/2016
Project 2
*/

import java.util.Scanner;

public class Tester
{
   public static void main (String[] args)
   {
      System.out.println("Programmed by William Tennis\n");
      Vehicle Vehicle_1=new Vehicle();
      Vehicle_1.info();
      Vehicle Vehicle_2=new Vehicle("Red");
      Vehicle_2.info();
      Car Car_1=new Car(3);
      Car_1.info();  
      Car Car_2=new Car("Brown",5);
      Car_2.info();      
      return;
   }
}