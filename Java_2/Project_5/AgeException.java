public class AgeException extends Exception{

   public AgeException(){
      super("Age is negative.");
   }
   public AgeException(int age){
      super("The age "+age+" is too much to be true.");
   }
}