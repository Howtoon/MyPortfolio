public class Car extends Vehicle
{
   public Car (String clr)
   {
      super.setColor(clr);
   }
   
   public void info()
   {
      System.out.println("I am a "+super.getColor()+" color car.");
      return;
   }
}