public class Cat implements Comparable{
   private int age;
   private int height;
   
   public Cat(int a){
      age=a;
   }
   public String toString(){
      return "Age: "+age;
   }
   public int compareTo(Object other){
      Cat otherCat=(Cat)other;
      if (this.age>otherCat.age){
         return -1;
      }
      if (this.age<otherCat.age){
         return 1;
      }
      return 0;
   }
}