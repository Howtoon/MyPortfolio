package trivia_game;

import java.util.*;

/**
 * @author Cole Peaden
 *
 */
public class QuestionList {
	
    private ArrayList<Question> questionList = new ArrayList<>();
    private final ArrayList<Question> workingList = new ArrayList<>();
    private Question currentQuestion;
    private final Random nums;
    
    public QuestionList(ArrayList<Question> questionList)
    {
        this.questionList = questionList;
        nums = new Random();
        createWorkingList();
    }

    public boolean isEmpty()
    {
        return questionList.isEmpty();
    }

    /**
     * Method randomizes the existing ArrayList for game...
     * 
     */
    public void createWorkingList()
    {
        if (questionList.size()>=5)
        {
            do
            {
                int randomIndex = nums.nextInt(questionList.size());
                if (!workingList.contains(questionList.get(randomIndex)))
                {
                    workingList.add(questionList.get(randomIndex));
                }
            }
            while(workingList.size() < 5);
        }
        
    }
    /**
     * Method checks to see if ArrayList has a following question.
     * @return boolean
     */
    public boolean hasNextQuestion()
    {
        if (this.workingList.size()==0)
        {
            return false;
        }
        else
        {
            return true;
        }
    }

    /**
     * Method prints current question given there is one.
     * @return Question
     */
    public Question getNextQuestion()
    {
        this.currentQuestion = workingList.remove(0);
        return currentQuestion;

    }	
}