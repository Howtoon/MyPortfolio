import javax.swing.JFrame;
import javax.swing.JButton;
import java.awt.event.ActionListener;

public class APR06{
   public static void main(String[]args){
      JFrame frame = new JFrame("Example of awesome Frame");
      frame.setSize(600,400);
      frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
      //frame.setTitle("Example Frame");
      JButton button = new JButton("Say Hello");
      frame.add(button);
      ActionListener listener1= new ListenerHello();
      button.addActionListener(listener1);
      
      
      frame.setVisible(true);
   }
}