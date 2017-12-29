/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package advanced_project_2;

/**
 *
 * @author Howtoon
 */
public class Trie 
{
    private class TrieNode 
    {
        TrieNode[] children;
        boolean isWord;
        public TrieNode() 
        {
            children = new TrieNode[26];        //26 children, one for each of the letters in the alphabet.
            for (int i = 0; i < 26; i++)
            {
                children[i] = null;
            }
            isWord = false;
        }
    }
    
    private final TrieNode root;
    public Trie() 
    {
        root = new TrieNode();
    }

    public void insert(String word)
    {
            
        TrieNode current = root;
        for (int i = 0; i < word.length(); i++) 
        {
            char ch = word.charAt(i);       //get current character
            if (ch-'a'>25 || ch-'a'<0)      //checks to make sure all characters are within the range of alphabet
            {
                return;                     //dont insert, this String is corrupt, not a word, goto next word
            }
            TrieNode node = current.children[(ch-'a')];     //sets index to ascii value of the character
            if (node == null)               //if the child is null
            {
                node = new TrieNode();              //create a new trienode
                current.children[(ch-'a')] = node;  //set the child index that corresponds to the ascii value to the new trie node
            }
            current = node;             //traverse to the next level of the trie that corresponds to the ascii value of the current char
        }
        current.isWord = true;          //reaches the end of the word, sets the bool
    }

    public Character getNextRandom(String word)     //picks a random next char from available paths, will always return a char if one exists
    {
        Character c;
        if (word!=null)         //check for start of game.
        {
            TrieNode current = root;        //start at the root
            for (int i = 0; i < word.length(); i++)     //iterates throught the word char by char
            {
                char ch = word.charAt(i);
                if (word.charAt(i)-'a'<0 || word.charAt(i)-'a'>25)      //check for valid input
                {
                    return null;
                }
                TrieNode node = current.children[(ch-'a')];         //traverse through the trie
                current = node;
            }
            if (current == null)            //if the char that the player entered does not exist, this is an invalid word
            {
                return null;
            }
            else        //the computer player picks the next letter at random.
            {
                int random = (int)(Math.random()*(current.children.length-1));

                while (current.children[random] == null)
                {
                    random = (int)(Math.random()*(current.children.length-1));
                }
                return ((char) ('a'+random));
            }
        }
        else        //start of game, random char is returned.
        {
            return (char)((int)(Math.random()*(root.children.length-1)));
        }
    }
    
    public boolean search(String word) //checks to see if the current String is a word.
    {
        TrieNode current = root;
        for (int i = 0; i < word.length(); i++) //traverse through the trie
        {
            char ch = word.charAt(i);
            if (ch-'a'>25 || ch-'a'<0) //checks for validity of input
            {
                return false;
            }
            TrieNode node = current.children[(ch-'a')];
            if (node == null)  ////if the child does not exist, this cannot be a word
            {
                return false;
            }
            current = node;
        }
        return current.isWord;      //reaches the end of the String and returns the value of isWord
    }
}
