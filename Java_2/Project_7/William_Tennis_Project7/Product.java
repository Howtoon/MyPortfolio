import java.io.Serializable;

public class Product implements Serializable{
   private String name=null;
   private double price=0;
   
   public Product(){
      name="NoName";
      price=1000.00;
   }
   public Product(String n,double p){
      name=n;
      price=p;
   }
   public void setName(String n){
      name=n;
   }
   public String getName(){
      return name;
   }
   public void setPrice(double p){
      price=p;
   }
   public double getPrice(){
      return price;
   }
   public void raisePrice(){
      price+=price*.1;
   }
   public String toString(){
      return name+" Price: "+price;
   }
}