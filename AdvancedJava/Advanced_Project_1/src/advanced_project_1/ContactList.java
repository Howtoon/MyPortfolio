/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package advanced_project_1;
import javax.swing.*;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;

/**
 *
 * @author wwt1
 */
public class ContactList extends JPanel{
    private Contact[] contactList = new Contact[4];
    private int numberOfElements = 0;
    public void createArray()
    {
        //Contact(John, Pete, Paul, George)
    
        Contact contact1 = new Contact( 1, "John", "John.jpg", "John is cool" );
        this.contactList[0] = contact1;
        Contact contact2 = new Contact( 2, "Pete", "Pete.jpg", "Pete is not cool" );
        this.contactList[1] = contact2;
        Contact contact3 = new Contact( 3, "Paul", "Paul.jpg", "Paul is cool" );
        this.contactList[2] = contact3;
        Contact contact4 = new Contact( 4, "George", "George.jpg", "George is cool" );
        this.contactList[3] = contact4;
        numberOfElements = 4;
    }
    public void addComponents()
    {
        for (int i=0; i<numberOfElements; i++){

            JList<String> list = new JList<Contact>(contactList);
            this.add(list);
        //}
        
        
    }
    
    
}
