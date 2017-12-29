import javax.swing.*;
import java.awt.*;

public class Apr11_square{
   public static void main(String[]args){
      JFrame frame= new JFrame("Calculate square of a number");
      frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
      frame.getContentPane().setBackground(Color.WHITE);
      frame.setSize(600,400);
      frame.setLayout(new GridLayout(4,3));
      for (int i=1;i<=10;++i){
         frame.add(new JButton(""+i));
      }
      frame.setVisible(true);
   }
}