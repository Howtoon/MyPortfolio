public class Person{
   private String fullname;
   private int age;
      private class Address{
         private String city;
         private String state;
         
         private void showAddress(String home){
            System.out.p  
        

      
   
   public void setName(String f){
      fullname=f;
   }
   public void setAge(int a){
      age=a;
   }
   public void setCity(String c){
      city=c;
   }
   public void setState(String s){
      state=s;
   }
   
   public void personInfo(){
      System.out.printf("%s\t%i\t%s\t%s",fullname,age,city,state);
   }
}