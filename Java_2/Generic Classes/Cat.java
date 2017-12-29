public class Cat <T>{
   private String name;
   private T age;
   
   public Cat(String n,T a){
      name=n;
      age=a;
   }
   public void info(){
      System.out.println(name+":"+age);
   }
   
   public String toString(){
      return name+":"+age;
   }
}