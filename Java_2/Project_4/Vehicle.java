public class Vehicle
{
   private int speed;
   
   public Vehicle ()
   {
   }
   
   public Vehicle (int spd)
   {
      this.setSpeed(spd);
   }
   
   public void setSpeed(int spd)
   {
      speed=spd;
   }
   
   public int getSpeed()
   {
      return speed;
   }
   
   public int getRaceSpeed()
   {
      return (speed*2);
   }
   
   public void compareRaceSpeeds(Vehicle a)
   {
      System.out.print("My race speed ("+this.getRaceSpeed()+") is ");
      if (this.getRaceSpeed()>a.getRaceSpeed())
         System.out.print("faster than");
      else if (this.getRaceSpeed()<a.getRaceSpeed())
         System.out.print("slower than");
      else
         System.out.print("equal to");
      System.out.println(" "+a.getRaceSpeed());
      return;
   }
}