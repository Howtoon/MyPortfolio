/**
 * Created by William Tennis on 4/4/16.
 */

import java.util.ArrayList;

public class P9{
   public static void main(String[]args){ 
      double average=0;
      double sum=0;
      int count=0; 
      System.out.println("Written by William Tennis\n");
      Score<Double> s1= new Score<>("Donatello",3.0);
      Score<String> s2= new Score<>("April","Five");
      Score<Double> s3= new Score<>("Raphael",3.5);
      Score<String> s4= new Score<>("Shredder","One");
      Score<String> s5= new Score<>("Splinter","Seven");
      ArrayList<Score> scores = new ArrayList<>();
      scores.add(s1);
      scores.add(s2);
      scores.add(s3);
      scores.add(s4);
      scores.add(s5);
      for (Score list:scores){
         System.out.println(list.toString());
         if (list.getScore()instanceof Double){
            ++count;
            sum+=(double)list.getScore();
         }
      }
      if (count!=0){
         average = sum/count;
      }
      
      System.out.println("\nAverage of numerical scores: "+average);

   }
}
      
      



