/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package advanced_project_2;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;

/**
 *
 * @author Howtoon
 */
public class Dictionary
{
    Trie dictionary;        //create the Trie
    String filename;        //filename
    public void readFile(String fileNAME)
    {
        dictionary = new Trie();
        filename = fileNAME;
        try             //try to read the file
        {
            File file = new File(filename);
            try (FileReader fileReader = new FileReader(file)) {
                BufferedReader bufferedReader = new BufferedReader(fileReader);
                String line;
                while ((line = bufferedReader.readLine()) != null)      //read the file line by line
                {
                    boolean isWord = true;      //assume the line contains a word
                    if (line.length()<4)    //if the line is less than 4 characters
                    {
                        //isWord = false;     //this is not a valid word //unnecessary, is never used
                        continue;           //goto the next word
                    }
                    
                    for (int i = 0; i<line.length(); i++)   //look for invalid characters in the line
                    {
                        if (line.charAt(i)-'a'<0 || line.charAt(i)-'a'>25)
                        {
                            isWord = false;     //invalid character found
                            break;              //exit loop
                        }
                    }
                    if (!isWord)        //if an invalid character was found
                    {
                        continue;       //goto next line
                    }
                    this.dictionary.insert(line);       //this is a valid word, insert it into the Trie
                }
            }
        } catch (IOException e) {
        }
    }
}
