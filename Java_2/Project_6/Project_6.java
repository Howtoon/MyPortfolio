import java.util.*;

import java.io.*;

public class Project_6{
   public static void main(String[]args){
      Scanner fileIn= null;
      String input=null, output=null;
      PrintWriter txtWriter=null;
      int number;
      int bytes=0;
      boolean notFinished=true,exists=true;
      System.out.println("Written by William Tennis\n");
      while (notFinished){
         try{
            System.out.print("Enter the input file name: ");
            Scanner keyboard = new Scanner(System.in);
            input = keyboard.next();
            FileInputStream inStream=new FileInputStream(input);
            fileIn=new Scanner(inStream);
            while (exists){
               System.out.print("Enter the output file name: ");
               output = keyboard.next();
               File file = new File(output);
               if(file.exists()){
                  System.out.println("File exists ("+file.length()+" bytes)");  
                  continue;
               }
               FileOutputStream txtStream= new FileOutputStream(output);
               txtWriter= new PrintWriter(txtStream);
               exists=false;
            }
            while (fileIn.hasNextInt()){
               number=fileIn.nextInt();
               if (number%2==0)
                  txtWriter.println(number);
            }
            txtWriter.close();
            inStream.close();
            notFinished=false;
         }
         catch (FileNotFoundException e){
            System.out.println("File does not exist.");
         }
         catch (IOException e){
            System.out.println("IOException   .");
         }
      }
      System.out.println("All even numbers from "+input+" were written to "+output);
      System.out.println("Goodbye...");
   }
}