import javax.swing.JFrame;
import javax.swing.JButton;
import javax.swing.JLabel;
import java.awt.*;
import java.awt.event.*;
import java.awt.event.ActionEvent;
import javax.swing.*;



public class APR06{
   private static int balance = 1000;

   public static void main(String[]args){
      JFrame frame = new JFrame("Example of awesome Frame");
      frame.setLayout(new BorderLayout());
      frame.setSize(600,400);
      frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
      frame.getContentPane().setBackground(Color.YELLOW);
      //frame.setTitle("Example Frame");
      JButton button = new JButton("Deposit $100.00");
      JTextField tf = new JTextField(3);
      JPanel panelDeposit = new JPanel(new FlowLayout());
      panelDeposit.setBackground(Color.GREEN);
      panelDeposit.add(tf);
      panelDeposit.add(button);
      frame.add(panelDeposit,BorderLayout.SOUTH);
      
      //JButton button2 = new JButton("NORTH");
      
      //frame.add(button2,BorderLayout.NORTH);
      JButton buttonExit = new JButton("EXIT");
      frame.add(buttonExit,BorderLayout.EAST);
         
      //JButton button4 = new JButton("WEST COAST BITCH");
      //frame.add(button4,BorderLayout.WEST);
      //JButton button5 = new JButton("CENTER");
      //frame.add(button5,BorderLayout.CENTER);
   
      //frame.add(button);
      JLabel label = new JLabel("$"+balance);
      //frame.add(label, BorderLayout.NORTH);
               
      class ListenerInner implements ActionListener{
         public void actionPerformed(ActionEvent arg0){
            if (arg0.getActionCommand().equals("EXIT")){
               System.exit(0);
            }
            else if (arg0.getActionCommand().equals("Deposit $100.00")){
               balance+=Integer.parseInt(tf.getText());
               label.setText("$"+balance);
            }
         }
      }
      
      ActionListener listener2 = new ListenerInner();
      buttonExit.addActionListener(listener2);
   
      
      class ListenerHello implements ActionListener{
         public void actionPerformed(ActionEvent arg0){
            balance+=100;
            label.setText("$"+balance);
         
         }
      
      }
      
      ActionListener listener1= new ListenerInner();
      button.addActionListener(listener1);
   
            
      frame.setVisible(true);
   }
}