package trivia_game;


import java.util.ArrayList;
import java.util.Scanner;
import java.io.*;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 * @author Cole Peaden
 *
 */
public class Storage
{
    private final String OS = System.getProperty("os.name").toLowerCase();
    
    private File questionFile;
    private File playerFile;
    private final Scanner in = new Scanner(System.in);
    public Player player = null;
    private final ArrayList<Player> players = new ArrayList<>();
    private final ArrayList<Question> questions = new ArrayList<>();
    private RandomAccessFile questionOut;
    private RandomAccessFile playerOut;
    private QuestionList questionList;
    
    public Storage()
    {
        questionFile = new File("questions.dat");
        playerFile = new File("players.dat");
        try
        {
            if (questionFile.exists())
            {
                this.readQuestionsFromFile();
            }
            else
            {
                questionOut = new RandomAccessFile(questionFile, "rw");
            }
        } catch (FileNotFoundException ex)
        {
            Logger.getLogger(Storage.class.getName()).log(Level.SEVERE, null, ex);
        }
        try
        {

            if (playerFile.exists())
            {
                this.readPlayerFile();
            }
            else
            {
                playerOut = new RandomAccessFile(playerFile, "rw");
            } 
        } catch (FileNotFoundException ex)
        {
            Logger.getLogger(Storage.class.getName()).log(Level.SEVERE, null, ex);
        }
        questionList = new QuestionList(questions);
        System.out.println(this.questionList.hasNextQuestion());
    }
    
    public void menu()
    {
        
        System.out.println("Welcome to the Trivia Game Administration Menu.");
        System.out.println("____________________________________________");
        String ans2;
        boolean isNotDone = true;
        
        do{
            System.out.println("1: List All Questions...");
            System.out.println("2: Delete a Question...");
            System.out.println("3: Add a Question...");
            System.out.println("4: Quit...");
            System.out.println("____________________________________________");
            System.out.println("Enter Choice:");

            String ans = in.nextLine();
            if (ans.compareToIgnoreCase("1")==0)
            {
                listAllQuestions();
            }
            else if(ans.compareToIgnoreCase("2")==0)
            {
                deleteQuestion();
            }
            else if (ans.compareToIgnoreCase("3")==0)
            {
                addQuestion();
            }
            else if (ans.compareToIgnoreCase("4")==0)
            {
                System.exit(0);
            }
            else if (ans.compareToIgnoreCase("1")!=0 && ans.compareToIgnoreCase("2")!=0 && ans.compareToIgnoreCase("3")!=0 && ans.compareToIgnoreCase("4")!=0)
            {
                System.out.print("Invalid option Please try again.\n");
                continue;
            }
            System.out.println("Need another? [Y/N]: ");
            ans2 = in.next();
            if(ans2.compareToIgnoreCase("N")==0)
            {
                isNotDone = false;
            }
        }
        while(isNotDone);
    }

    public void readQuestionsFromFile()
    {
        try
        {
            RandomAccessFile raf = new RandomAccessFile(this.questionFile, "rw");
            while(raf.getFilePointer()<raf.length())
            {
                Question questionObject = new Question(raf.readInt());
                questionObject.setQuestion(raf.readUTF());
                questionObject.setAnswer(raf.readUTF());
                questionObject.setValue(raf.readInt());
                questions.add(questionObject);
            }
        }
        catch(IOException e)
        {
            e.printStackTrace();
        }
    }
    
    public void writeQuestionsToFile(ArrayList<Question> questions)
    {
        try
        {
            System.out.println(questionFile.getAbsolutePath());
            if(this.questionFile.exists())
            {
                boolean throwAway = this.questionFile.delete();
            }
            RandomAccessFile raf = new RandomAccessFile(this.questionFile, "rw");
            for (int i=0; i<questions.size(); i++)
            {
                raf.writeInt(questions.get(i).getQuestID());
                raf.writeUTF(questions.get(i).getQuestion());
                raf.writeUTF(questions.get(i).getAnswer());
                raf.writeInt(questions.get(i).getValue());
            }
            raf.close();
        }
        catch(IOException e)
        {
            e.printStackTrace();
        }
        //write all questions to file
    }

    public void readPlayerFile()
    {
        try
        {
            RandomAccessFile raf = new RandomAccessFile(this.playerFile, "rw");
            while(raf.getFilePointer()<raf.length())
            {
                Player playerObject = new Player(raf.readUTF(), raf.readUTF());
                playerObject.setTotalPoints(raf.readInt());
                players.add(playerObject);
            }
        }
        catch(IOException e)
        {
            e.printStackTrace();
        }
    }
    
    public void writePlayerFile()
    {
        try
        {
            if(this.playerFile.exists())
            {
                boolean throwAway = this.playerFile.delete();
            }
            RandomAccessFile raf = new RandomAccessFile(this.playerFile, "rw");
            for (int i=0; i<this.players.size(); i++)
            {
                raf.writeUTF(this.players.get(i).getName());
                raf.writeUTF(this.players.get(i).getNickName());
                raf.writeInt(this.players.get(i).getTotalPoints());
            }
            raf.close();
        }
        catch(IOException e)
        {
            e.printStackTrace();
        }
    }
    
    public void deleteQuestion()
    {
        System.out.println("Enter Question's ID: ");
        int ID = in.nextInt();
        boolean foundIt = false;
        System.out.println(questions.size());
        for(int i=0; i < questions.size(); i++)
        {
            if(questions.get(i).getQuestID()==ID)
            {
                questions.remove(i);
                foundIt = true;
            }
        }
        if (!foundIt)
        {
            System.out.println("Did not find the question you were trying to delete.");
        }
        this.writeQuestionsToFile(questions);
    }

    public void addQuestion()
    {        
        boolean notDone = true;
        int ID = 0;
        String input;
        while(notDone)
        {
            System.out.println("Enter Question ID: ");

            input = in.nextLine();
            try
            {
                ID = Integer.parseInt(input);
                notDone = false;
            }
            catch(NumberFormatException e)
            {
                System.out.println("Please enter a whole number");
            }
        }
        Question newQuest = new Question(ID);

        notDone = true;
        
        while(notDone){
            System.out.println("Enter Question: ");
            input = in.nextLine();

            if (input.length() <= 50)
            {
                newQuest.setQuestion(input);
                notDone = false;
            }

            else
            {
                System.out.println("ERROR: too many characters. Must be at most 50.");
                notDone = true;
            }
        }

        notDone = true;

        while (notDone)
        {
            System.out.println("Enter Answer: ");
            input = in.nextLine();
            if (input.length() <= 20)
            {
                newQuest.setAnswer(input);
                notDone = false;
            }

            else
            {
                System.out.println("ERROR: too many characters. Must be at most 20.");
                notDone = true;
            }
        }

        notDone = true;

        while(notDone)
        {
            System.out.println("Enter Value: ");
            int val = in.nextInt();

            if (val <= 5 && val >=1 )
            {
                newQuest.setValue(val);
                notDone = false;
            }

            else
            {
                System.out.println("ERROR: Must be at most 5.");
                notDone = true;
            }
        }
        System.out.println(questions.size());
        questions.add(newQuest);
        System.out.println(questions.size());
        this.writeQuestionsToFile(questions);
    }    
    /*
    *
    */
    public Player createNewPlayer()
    {
        System.out.println("Enter your name: ");
        String name = in.nextLine();
        System.out.println("Enter a nickname: ");
        String nickname = in.nextLine();
        System.out.println("");
        this.player = new Player(name, nickname);
        this.players.add(player);
        this.writePlayerFile();
        return player;
    }
    
    public Player getPlayer(String name)
    {
        for(int i=0; i<players.size(); i++)
        {
            if (players.get(i).getName().compareToIgnoreCase(name)==0)
            {
                player = players.get(i);
                break;
            }
        }
        return player;
    }
    
    public QuestionList getQuestionList()
    {
        return questionList;
    }
    
    public void listAllQuestions()
    {
        Question question;
        for(int i =0; i<this.questions.size(); i++)
        {
            question = questions.get(i);
            System.out.println("\nQuestion ID: "+question.getQuestID());
            System.out.println("Question: "+question.getQuestion());
            System.out.println("Answer: "+question.getAnswer());
            System.out.println("Value: "+question.getValue());
        }
    }
}
