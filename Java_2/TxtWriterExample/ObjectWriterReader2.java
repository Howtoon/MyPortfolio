import java.io.*;
import java.util.*;


public class ObjectWriterReader2{
   public static void main(String[]args){
      try{
         RandomAccessFile fileIn = new RandomAccessFile("file2.bin","rw");
         fileIn.writeByte(10);
         System.out.println("Length: "+fileIn.length());
         fileIn.writeByte(20);
         fileIn.writeByte(30);
         System.out.println("Length: "+fileIn.length());
         System.out.println("File pointer: "+fileIn.getFilePointer());
         fileIn.seek(0);
         
         Byte b1=fileIn.readByte();
         System.out.println("Byte b1: "+b1);
         System.out.println(b1);
         System.out.println(fileIn.readByte());
         System.out.println(fileIn.readByte());
         /*fileIn.writeDouble(12.34);
         fileIn.seek(3);
         System.out.println(fileIn.readDouble());
         fileIn.seek(fileIn.getFilePointer()-8);
         
         System.out.println(fileIn.readDouble());
         */
         fileIn.seek(1);
         fileIn.writeByte(90);
         fileIn.seek(1);
         System.out.println(fileIn.readByte());
         fileIn.seek(fileIn.length());
         fileIn.writeByte(44);
         fileIn.seek(fileIn.length()-1);
         System.out.println(fileIn.readByte());

         
         fileIn.close();
      
      }
      
      catch (FileNotFoundException e){
         System.out.println("Can't Open");
      }
      catch(IOException e){
         e.printStackTrace();
      }
   }
}