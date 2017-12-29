public class P8{
   public static void main(String[]args){
      System.out.println("Written by William Tennis\n");
      Cat cat1=new Cat("Garfield");
      Bird bird1=new Bird("Tweety");
      Cat cat2=new Cat("Sylvester");
      MovingAnimalInterface arr[]= {cat1,bird1,cat2};
      for (MovingAnimalInterface array:arr){
         System.out.print(array.toString());
         array.move();
      }
   }
}