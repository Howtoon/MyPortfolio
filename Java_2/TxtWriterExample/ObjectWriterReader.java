import java.io.*;
import java.io.ObjectOutputStream;

public class ObjectWriterReader{
   public static void main(String[]args){
      try{
         ObjectOutputStream fileOut= new ObjectOutputStream(new FileOutputStream("file1.bin"));
         Person p1 = new Person ("Michael Jordan", 53);
         fileOut.writeObject(p1);
         Person p3 = new Person ("Kobe Bryant", 37);
         fileOut.writeObject(p3);
         fileOut.flush();
         fileOut.close();
         System.out.println("Done");
      }
      catch (IOException e){
         System.out.println("IOException.");
      }
      try{
         ObjectInputStream fileIn = new ObjectInputStream(new FileInputStream("file1.bin"));
         Person p5=(Person)fileIn.readObject();
         System.out.println(p5);
         Person p3=(Person)fileIn.readObject();
         System.out.println(p3);
         fileIn.close();
      }
      catch(IOException e){
         System.out.println("IOException.");
      }
      catch(ClassNotFoundException e){
         e.printStackTrace();
      }

   }  
}