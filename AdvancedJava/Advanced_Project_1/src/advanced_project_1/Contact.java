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
public class Contact {
    
    private int ID;
    private String name, picture, comment;
    public Contact(int ID, String name, String picture, String comment )
    {
        this.ID = ID;
        this.name = name;
        this.picture = picture;
        this.comment = comment;
    }
    
    public int getID()
    {
        return ID;
    }
    
    public String getName()
    {
        return name;
    }
    
    public String getPicture()
    {
        return picture;
    }

    public String getComment()
    {
        return comment;
    }
}
