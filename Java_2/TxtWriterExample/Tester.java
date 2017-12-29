import java.io.FileOutputStream;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.io.FileInputStream;
import java.util.Scanner;

public class Tester{
   public static void main(String[] args){
      Scanner fin=null;
      String Line1=null, Line2=null;
      try{
         FileInputStream inStream=new FileInputStream("a.txt");
         fin=new Scanner(inStream);
      }catch (FileNotFoundException e){
         System.out.println("File does not exist or cannot be opened");
      }
      if (fin.hasNextLine())
         Line1=fin.nextLine();
      if (fin.hasNextLine())
         Line2=fin.nextLine();
      else System.out.println("No Line.");
      System.out.println(Line1+"\n"+Line2);
      System.out.println("Goodbye");
      //txtWriter.close();
      PrintWriter txtWriter = null;
      try{
         FileOutputStream txtStream= new FileOutputStream("a.txt");
         txtWriter= new PrintWriter(txtStream);
      } catch (FileNotFoundException e) {
         System.out.println("File cannot be opened");
         System.exit(0);
      }
      txtWriter.println("Knock Knock");
      txtWriter.println("Who's There?");
      System.out.println("Banana");
      txtWriter.close();
   }
}