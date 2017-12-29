
public class NumOutOfBoundsException extends Exception{
	
	/**
	 * 
	 */
	private static final long serialVersionUID = 1L;
	int num;
	Question questException = new Question(num);
	
	String str;
	NumOutOfBoundsException(str);
	{
		
		String quest = questException.getQuestion();
		int questLen = quest.length();
	
	if (questLen < 50)
	{
		str = "Question longer than 50 bytes.";
		NumOutOfBoundsException(str);
	}

}
}
