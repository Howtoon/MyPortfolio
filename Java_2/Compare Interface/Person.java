public class Person{
   private String fullname;
   private int age;
   private String city;
   private String state;
   
   public setName(String f){
      fullname=f;
   }
   
   public void personInfo(){
      System.out.printf("%s\t%i\t%s\t%s",fullname,age,city,state);
   }
}