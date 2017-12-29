import java.util.*;

/**
 * @author Cole Peaden
 *
 */
public class QuestionList {
	
	private ArrayList<Question> questionList = new ArrayList<>();
	private ArrayList<Question> workingList = new ArrayList<>();
	private Question currentQuestion;
	private Random nums = new Random();
	
	public QuestionList(ArrayList<Question> questionList)
	{
		this.questionList = questionList;
	}
	
	public boolean isEmpty(){
		if (questionList.isEmpty() == true){
			return true;
		}
		
		else {
			return false;
		}
	}
	
	/**
	 * Method randomizes the existing ArrayList for game...
	 * @return ArrayList
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
			while(workingList.size() > 5);
	
		}
	}
	/**
	 * Method checks to see if ArrayList has a following question.
	 * @return boolean
	 */
	public boolean hasNextQuestion()
	{
		if (workingList.size()>0)
		{
			return true;
		}
		else
			return false;
	}
	
	/**
	 * Method prints current question given there is one.
	 */
	public Question getQuestion()
	{
		this.currentQuestion = workingList.remove(0);
		return currentQuestion;
	}
	
	
}
