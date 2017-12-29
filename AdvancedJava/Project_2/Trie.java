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
            children = new TrieNode[26];
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
            if (i < word.length()-1)
            {
                if (current.isWord)
                {
                    current.isWord = false;
                }
            }
            char ch = word.charAt(i);
            if (ch-'a'>25 || ch-'a'<0)
            {
                continue;
            }
            TrieNode node = current.children[(ch-'a')];
            if (node == null) 
            {
                node = new TrieNode();
                current.children[(ch-'a')] = node;
            }
            current = node;
        }
        current.isWord = true;
    }

    public Character getNextRandom(String word)
    {
        Character c;
        if (word!=null)
        {
            TrieNode current = root;
            for (int i = 0; i < word.length(); i++) 
            {
                char ch = word.charAt(i);
                TrieNode node = current.children[(ch-'a')];
                current = node;
            }
            if (current == null)
            {
                return null;
            } 
            else 
            {
                int random = (int)(Math.random()*(current.children.length-1));

                while (current.children[random] == null)
                {
                    random = (int)(Math.random()*(current.children.length-1));
                }
                return ((char) ('a'+random));
            }
        }
        else
        {
            return (char)((int)(Math.random()*(root.children.length-1)));
        }
    }
    
    public boolean search(String word) 
    {
        TrieNode current = root;
        for (int i = 0; i < word.length(); i++) 
        {
            char ch = word.charAt(i);
            if (ch-'a'>25 || ch-'a'<0)
            {
                return false;
            }
            TrieNode node = current.children[(ch-'a')];
            if (node == null) 
            {
                return false;
            }
            current = node;
        }
        return current.isWord;
    }
}
