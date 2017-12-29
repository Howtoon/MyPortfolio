import java.util.*;
public class Storage {

	private Scanner in = new Scanner(System.in);
	public void menu(){
		
		System.out.println("Welcome to the Question Administration Menu.");
		System.out.println("____________________________________________");
		
		String ans2 = "Y";
		do{
		
			System.out.println("Options:");
			System.out.println("Add a Question...");
			System.out.println("Delete a Question...");
			System.out.println("____________________________________________");
			System.out.println("Enter D for delete or A for add...");
			
			String ans = in.nextLine();
			if(ans.equals('d') || ans.equals('D'))
			{
				deleteQuestion();
			}
			else if (ans.equals('a') || ans.equals('A')){
				addQuestion();
			}
		
			System.out.println("Need another? [Y/N]: ");
		    ans2 = in.next();
		}
		while(ans2.equals('Y'));
		in.close();
	}
	
	public void writeData()
	{
		
	}
	
	public void deleteQuestion()
	{
		System.out.println("Enter Question's ID: ");
		int ID = in.nextInt();
		
		//findQuestion method???
		//		then delete the question.
		
		
	}
	
	public void addQuestion()
	{
		System.out.println("Enter Question ID: ");
		int ID = Integer.parseInt(in.nextLine());
		Question newQuest = new Question(ID);
		
		boolean done = true;
		
		while(!done){
			System.out.println("Enter Question: ");
			String question = in.nextLine();
			
			if (question.length() <= 50)
			{
				newQuest.setQuestion(question);
				done = true;
			}
			
			else
			{
				System.out.println("ERROR: too many characters. Must be at most 50.");
				done = false;
			}
		}
		
		boolean done2 = true;
		
		while (!done2)
		{
			System.out.println("Enter Answer: ");
			String ans = in.nextLine();
			if (ans.length() <= 20)
			{
				newQuest.setAnswer(ans);
				done2 = true;
			}
			
			else
			{
				System.out.println("ERROR: too many characters. Must be at most 20.");
				done2 = false;
			}
		}
		
		boolean done3 = true;
		
		while(!done3)
		{
			System.out.println("Enter Value: ");
			int val = in.nextInt();
			
			if (val <= 5)
			{
				newQuest.setValue(val);
				done3 = true;
			}
			
			else
			{
				System.out.println("ERROR: Must be at most 5.");
				done3 = false;
			}
		}
	}
	
	private void findQuestion()
	{
		System.out.println("Enter question ID: ");
		int newID = in.nextInt();
		
		//if newID is in file delete that, and rewrite file without it.
	}
	
	
	
	
	
}
