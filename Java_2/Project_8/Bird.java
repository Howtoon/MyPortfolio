public class Bird implements MovingAnimalInterface{
   private String name=null;
   public Bird(String n){
      name=n;
   }
   public void move(){
      System.out.println("I fly.");
   }
   public String toString(){
      return "I am the bird "+name+". ";
   }
}