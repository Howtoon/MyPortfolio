import java.io.Serializable;

public class Question implements Serializable {
	private String question;
	private String answer;
	private int value;
	private int questID;
	
	public Question(int questID)
	{
		this.questID = questID;
	}
	
	
	public String getQuestion(){
		return question;
	}
	
	public void setQuestion(String newQuest){
		question = newQuest;
	}

	/**
	 * @return the answer
	 */
	public String getAnswer() {
		return answer;
	}

	/**
	 * @param answer the answer to set
	 */
	public void setAnswer(String answer) {
		this.answer = answer;
	}

	/**
	 * @return the value
	 */
	public int getValue() {
		return value;
	}

	/**
	 * @param value the value to set
	 */
	public void setValue(int value) {
		this.value = value;
	}

	/**
	 * @return the questID
	 */
	public int getQuestID() {
		return questID;
	}
	
}
