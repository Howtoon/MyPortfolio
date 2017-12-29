/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package advanced_project_1;
import java.awt.Color;
import java.awt.GridLayout;
import javax.swing.*;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;

/**
 *
 * @author wwt1
 */
public class ContactList extends JPanel
{
    private int sizeOfArray = 4;
    private Contact[] contactList = new Contact[sizeOfArray];
    private int numberOfElements = 0;
    private int ID = 1;
    private JPanel listContacts = new JPanel();
    private JPanel buttons = new JPanel();
    private JPanel deleteContact = new JPanel();
    private JPanel addContact = new JPanel();
    
    public void createArray()
    {
        Contact contact1 = new Contact( ID, "John", "John.jpg", "John is cool" );
        this.contactList[0] = contact1;
        ID++;
        numberOfElements++;
        Contact contact2 = new Contact( ID, "Pete", "Pete.jpg", "Pete is not cool" );
        this.contactList[1] = contact2;
        ID++;
        numberOfElements++;
        Contact contact3 = new Contact( ID, "Paul", "Paul.jpg", "Paul is cool" );
        this.contactList[2] = contact3;
        ID++;
        numberOfElements++;
        Contact contact4 = new Contact( ID, "George", "George.jpg", "George is cool" );
        this.contactList[3] = contact4;
        ID++;
        numberOfElements++;
    }
    
    public void displayList(JFrame frame)
    {
        this.setLayout(new GridLayout(0,1));
        listContacts.setBackground(Color.CYAN);
        buttons.setBackground(Color.YELLOW);
        addContact.setBackground(Color.GREEN);
        deleteContact.setBackground(Color.GREEN);
        
        for (int i=0; i<numberOfElements; i++)
        {
            String[] list = {String.valueOf(contactList[i].getID()), contactList[i].getName(), contactList[i].getPicture(), contactList[i].getComment()};
            JList<String> myList = new JList<String>(list);
            listContacts.add(myList);
        }
        
        JButton btnSort = new JButton("Press to Sort");
        btnSort.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e)
            {
                buttons.removeAll();
                listContacts.removeAll();
                deleteContact.removeAll();
                addContact.removeAll();
                frame.remove(deleteContact);
                frame.remove(addContact);
                sortList();
                displayList(frame);
                frame.revalidate();
            }
        });
        buttons.add(btnSort);
        
        JButton btnDeleteContact = new JButton("Delete a Contact");
        btnDeleteContact.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e)
            {
                buttons.removeAll();
                listContacts.removeAll();
                deleteContact.removeAll();
                addContact.removeAll();
                
                frame.remove(addContact);
                frame.remove(deleteContact);
                displayList(frame);
                frame.revalidate();
                deleteContact(frame);
            }
        });
        buttons.add(btnDeleteContact);
        
        JButton btnAddContact = new JButton("Add a Contact");
        btnAddContact.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e)
            {
                buttons.removeAll();
                listContacts.removeAll();
                deleteContact.removeAll();
                addContact.removeAll();
                
                frame.remove(deleteContact);
                frame.remove(addContact);
                displayList(frame);
                frame.revalidate();
                addContact(frame);   
            }
        });
        buttons.add(btnAddContact);
        
        this.add(listContacts);
        this.add(buttons);
    }
    public void sortList()
    {
        for(int t=0; t<10 ; t++)
        {
            for (int i = 1; i < numberOfElements; i++) 
            {   
                int s = i-1;
                for (int j = i; j < numberOfElements; j++) 
                {
                    if (contactList[j].getName().compareToIgnoreCase(contactList[s].getName()) < 0) 
                    {
                    s = j;
                    break;
                    }
                }
            Contact temp = contactList[i-1];
            contactList[i-1] = contactList[s];
            contactList[s] = temp;
            }
        }
    }
    
    public void deleteContact(JFrame frame)
    {
        JLabel nameLabel = new JLabel("Name: ");
        deleteContact.add(nameLabel);
        JTextField nameTF = new JTextField(20);
        deleteContact.add(nameTF);
        JButton btnDelete = new JButton("Delete");
        btnDelete.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e)
            {
                for (int i=0; i<numberOfElements; i++)
                {
                    if (nameTF.getText().compareToIgnoreCase(contactList[i].getName()) == 0)
                    {
                        contactList[i] = contactList[numberOfElements-1];
                        contactList[numberOfElements-1] = null;
                        numberOfElements--;
                        break;
                    }
                }
                deleteContact.removeAll();
                addContact.removeAll();
                buttons.removeAll();
                listContacts.removeAll();
                frame.remove(deleteContact);
                frame.remove(addContact);
                
                displayList(frame);
                frame.revalidate();
            }
        });
        deleteContact.add(btnDelete);
        this.add(deleteContact);
        frame.revalidate();
    }
    
    public void addContact(JFrame frame)
    {
        addContact.setLayout(new GridLayout(0,2));
        addContact.setBackground(Color.GREEN);
        
        JLabel nameLabel = new JLabel("Name: ");
        addContact.add(nameLabel);
        JTextField nameText = new JTextField(20);
        addContact.add(nameText);
        
        JLabel pictureLabel = new JLabel("Picture File Name: ");
        addContact.add(pictureLabel);
        JTextField pictureText = new JTextField(20);
        addContact.add(pictureText);
        
        JLabel commentLabel = new JLabel("Comments: ");
        addContact.add(commentLabel);
        JTextField commentText = new JTextField(20);
        addContact.add(commentText);
        
        
        JButton btnAdd = new JButton("Add Contact");
        btnAdd.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e)
            {
                boolean exists = false;
                for (int i=0; i<numberOfElements; i++)
                {
                    if (nameText.getText().compareTo(contactList[i].getName()) == 0) ///Name Exists
                    {
                        //Throw Exception if Name Exists
                        exists = true;
                        break;
                    }
                }
                if (sizeOfArray == numberOfElements && !exists)
                {
                    growArray(contactList);
                    contactList[numberOfElements] = new Contact(ID, nameText.getText(), pictureText.getText(), commentText.getText() );
                    ID++;
                    numberOfElements++;
                    //Expand Array and add element
                }
                else if (sizeOfArray > numberOfElements && !exists)
                {
                    contactList[numberOfElements] = new Contact(ID, nameText.getText(), pictureText.getText(), commentText.getText() );
                    ID++;
                    numberOfElements++;
                    //Add element to end of list
                    
                }
                addContact.removeAll();
                deleteContact.removeAll();
                buttons.removeAll();
                listContacts.removeAll();
                frame.remove(deleteContact);
                frame.remove(addContact);
                
                if (exists)
                {
                    addContact.add(new JLabel("This Name: "+nameText.getText()+"    Already Exists"));
                    displayList(frame);
                    frame.add(addContact);
                }
                else
                {
                    displayList(frame);
                }
                frame.revalidate();
            }
        });
        addContact.add(btnAdd);
        this.add(addContact);
        frame.revalidate();
    }
    
    public void growArray(Contact[] oldArray)
    {
        
        Contact[] newArray = new Contact[sizeOfArray*2];
        sizeOfArray = sizeOfArray*2;
        for (int i=0; i<numberOfElements; i++)
        {
            newArray[i] = oldArray[i];
        }
        contactList = newArray;
    }
}
