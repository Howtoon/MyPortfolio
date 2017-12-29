public class Plane extends Vehicle
{
   public Plane()
   {
   }
   
   public Plane(int spd)
   {
      super.setSpeed(spd);
   }
   
   public int getRaceSpeed()
   {
      return (super.getSpeed()*3);
   }
}