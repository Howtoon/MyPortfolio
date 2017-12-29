public class Tester{
   public static void main(String[]args){
      Cat c1=new Cat<Integer>("C1",2);
      c1.info();
      Cat c2=new Cat<String>("C2","Five");
      c2.info();
   
      ArrayList a = new ArrayList<Cat>();
      a.add(c1);
      a.add(c2);
      for(Cat c: a){
         c.info();
      }
   
   
   }
}