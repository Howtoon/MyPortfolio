import java.io.*;
import java.util.*;

public class P7{
   public static void main(String[]args){
      System.out.println("Written by William Tennis");
      File file=new File("binary1.bin");
      if (!file.exists()){
         try{
            Product product=new Product();
            ObjectOutputStream fileOut= new ObjectOutputStream(new FileOutputStream("binary1.bin"));
            System.out.println(product); 
            product.setName("Garlic");
            product.raisePrice();
            System.out.println(product);
            fileOut.writeObject(product);
            fileOut.close();
         }
         catch(IOException e){
            System.out.println("IOException.");
         }
      }
      else{
         try{
            ObjectInputStream fileIn = new ObjectInputStream(new FileInputStream("binary1.bin"));
            Product product=(Product)fileIn.readObject();
            System.out.println(product);
            ObjectOutputStream fileOut= new ObjectOutputStream(new FileOutputStream("binary1.bin"));
            product.raisePrice();
            fileOut.writeObject(product);
            System.out.println(product);
            fileIn.close();
            fileOut.close();
         }
         catch(IOException e){
            System.out.println("IOException.");
         }
         catch(ClassNotFoundException e){
            System.out.println("ClassNotFoundException.");
         }
      }
   }
}
