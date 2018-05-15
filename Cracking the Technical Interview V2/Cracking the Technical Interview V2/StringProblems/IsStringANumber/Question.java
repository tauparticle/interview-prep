package IsStringANumber;

public class Question {
	
	public static Boolean IsStringANumber(String str)
	{
		if (str == null)
		{
			return false;
		}
		
		try
		{
			Double.parseDouble(str)
		}
		catch(NumberFormatException ex)
		{
			return false;
		}
		
		return true;
		
	}
	
	public static void main(String[] args) {
		String[] words = {"0.123", "-0.23", "-.231", "1231232.0003.00", "-874.90-32", "-."};
		for (String word : words) {
			System.out.println(word + ": " + IsStringANumber(word));
		}

	}

}
