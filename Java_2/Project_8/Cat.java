public class Cat implements MovingAnimalInterface{
   private String name=null;
   public Cat(String n){
      name=n;
   }
   public void move(){
      System.out.println("I run.");
   }
   public String toString(){
      return "I am the cat "+name+". ";
   }
}