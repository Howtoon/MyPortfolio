public abstract  class Vehicle
{
   private String color;
   
   public Vehicle ()
   {
   }
   
   public Vehicle (String clr)
   {
      this.setColor(clr);
   }
   
   public void setColor(String clr)
   {
      color=clr;
      return;
   }
   
   public String getColor()
   {
      return color;
   }
   
   public abstract void info();

}