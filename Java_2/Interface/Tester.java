import java.io.*;
import java.util.*;

public class Tester{
   public static void haveThemSpeak(Speakable speaker){
      speaker.speak();
   
   }
   public static void haveThemClimb(Climbable climber){
      climber.climb();
   }
   public static void main(String[]args){
      Cat c = new Cat();
      Dog d = new Dog();
      haveThemSpeak(c);
      haveThemSpeak(d);  
      haveThemClimb(c);
    }
}