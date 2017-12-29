/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package advanced_project_1;

/**
 *
 * @author wwt1
 */
public class Client{

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args)
    {   
        // TODO code application logic here
        GUIFrame frame = new GUIFrame();
        ContactList list = new ContactList();
        list.createArray();
        list.displayList(frame);
        frame.setVisible(true);
        frame.setContentPane(list);
        
    }
    
}
