import java.io.Serializable;

public class Person implements Serializable{
   private String name;
   private int age;

   public Person(String n,int a){
      name = n;
      age = a;
   }
   public String toString(){
      return "Name: "+name+"\tAge: "+age;
   }
}