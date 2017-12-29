import java.util.ArrayList;

public class Mar28{
   public static void main(String[] args){
      ArrayList<String> list = new ArrayList<>();
      list.add("AL");
      list.add("FL");
      list.add("GA");
      System.out.println(list);
      System.out.println("Size: "+list.size());
      list.add(1,"WA");
      System.out.println(list);
      System.out.println("Size: "+list.size());
      System.out.println("Index: "+list.indexOf("AL"));
      System.out.println("Index: "+list.indexOf("FL"));
      list.add("AL");
      System.out.println(list);  
      System.out.println("Index: "+list.indexOf("AL"));
      System.out.println("Index: "+list.lastIndexOf("AL"));
      list.set(list.size()-1,"TN");
      System.out.println(list);
      list.remove("WA");
      System.out.println(list);
      list.remove(list.size()-1);
      System.out.println(list);
      System.out.println(list.get(0));
      for (String item: list){
         System.out.print(item+" ");
         
      }
      System.out.println();
      System.out.println("Contains TX? "+list.contains("TX"));
      System.out.println("Contains AL? "+list.contains("AL"));
   return;  
   }
}