import java.util.*;
import java.io.*;

public class WriteBinary{
   public static void main(String[]args){
      try{
         Scanner kb = new Scanner(System.in);
         String input = kb.next();
         FileOutputStream pipe1= new FileOutputStream(input);
         ObjectOutputStream PrintWriter= new ObjectOutputStream(pipe1);
         PrintWriter.writeUTF("12345");
         PrintWriter.close();
      }catch (FileNotFoundException e){
         System.out.println("File cannot be opened");
      }catch (IOException e){
         System.out.println("IOException   .");
      }
      try{
         ObjectInputStream fin = new ObjectInputStream(new FileInputStream("bin1.txt"));
         System.out.println("Number: "+fin.readUTF());
         fin.close();
      }catch(IOException e){
         System.out.println("IOException   .");
      }
      System.out.println("Goodbye...");
   }
}