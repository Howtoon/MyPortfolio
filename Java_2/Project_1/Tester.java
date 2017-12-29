/**
Name:William Tennis
Date: 01/11/2016
Project 1
*/

import java.util.Scanner;

public class Tester
{
   public static void main (String[] args)
   {
   System.out.println("Programmed by William Tennis\n");
   Cheetah Vaisya= new Cheetah();
   Vaisya.setName("Vaisya");
   System.out.println("Name: "+Vaisya.getName());
   Vaisya.setCountry("Egypt");
   System.out.println("Country: "+Vaisya.getCountry());
   Vaisya.setSpeed(700);
   System.out.println("Speed: "+Vaisya.getSpeed()+"mph");
   Cheetah Toulouse= new Cheetah();
   Toulouse.setName("Toulouse");
   System.out.println("Name: "+Toulouse.getName());
   Toulouse.setCountry("France");
   System.out.println("Country: "+Toulouse.getCountry());
   Toulouse.setSpeed(700);
   System.out.println("Speed: "+Toulouse.getSpeed()+"mph");

   

   
   return;
   }
}

