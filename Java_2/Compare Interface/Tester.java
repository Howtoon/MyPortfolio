import java.util.*;

public class Tester{
   public static void main(String[]args){
      int[] a = {8,2,6,4};
      System.out.println(Arrays.toString(a));
      Arrays.sort(a);
      System.out.println(Arrays.toString(a));
      
      Double[] d = {80.0,20.0,60.0,new Double(40.0)};
      System.out.println(Arrays.toString(d));
      Arrays.sort(d);
      System.out.println(Arrays.toString(d));

      Cat[] c = new Cat[3];
      c[0] = new Cat(20);
      c[1] = new Cat(10);
      c[2] = new Cat(30);
      
      System.out.println(Arrays.toString(c));
      Arrays.sort(c);
      System.out.println(Arrays.toString(c));
      
   }
}