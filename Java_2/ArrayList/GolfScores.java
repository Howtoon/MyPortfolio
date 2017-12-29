import java.util.ArrayList;
import java.util.Scanner;

public class GolfScores{

   private static void fillArrayList(ArrayList<Double> list){
      Scanner kb = new Scanner(System.in);
      double num;
      num =kb.nextDouble();
         
      while(num>=0){
         list.add(num);
         num=kb.nextDouble();
      }
   
   }
   
   private static double getAverage(ArrayList<Double> list){
      if(list.isEmpty()){
         return 0;
      }
      else{
         double sum=0;
         for(Double item:list){
            sum+=item;
         }
         return sum/list.size();
      }
   }
   
   private static void showDifferences(ArrayList<Double> list){
      double avg=getAverage(list);
      for (Double item:list){
         System.out.print(item+" is ");
         if(item.doubleValue()<avg){
            System.out.print((avg)-(item.doubleValue())+" less than");
         }
         
         else if(item>avg){
            System.out.print(item.doubleValue()-avg+" more than");
         }
         
         else {
            System.out.print("the same as");
         }
         System.out.println(" average "+avg);
      }
   
   }

   public static void main(String[]args){
      ArrayList<Double> list=new ArrayList<>();
      System.out.println("Enter scores, and a negative number");
      /*Scanner kb = new Scanner(System.in);
      double num;
      num =kb.nextDouble();
         
      while(num>=0){
         list.add(num);
         num=kb.nextDouble();
      }*/
      fillArrayList(list);
      System.out.println(list);
      System.out.println(getAverage(list));
      showDifferences(list);
   }
}