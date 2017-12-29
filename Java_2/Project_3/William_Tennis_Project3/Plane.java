public class Plane extends Vehicle
{
   public Plane (String color)
   {
      super.setColor(color);
   }
   
   public void info()
   {
      System.out.println("I am a "+super.getColor()+" color plane.");
      return;
   }
}