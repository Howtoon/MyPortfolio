import java.io.*;

public class File_class_methods{
   public static void main(String[] args){
      File file1 = new File("c.txt");
      if (file1!=null){
         System.out.println("File exists.");
      }else{
         System.out.println("File does not exist.");
      }System.out.println("Length: "+file1.length());

}  }