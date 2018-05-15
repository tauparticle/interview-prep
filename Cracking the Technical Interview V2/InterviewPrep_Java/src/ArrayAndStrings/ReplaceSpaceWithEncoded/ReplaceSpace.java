package ArrayAndStrings.ReplaceSpaceWithEncoded;

public class ReplaceSpace {
	
	// replace ' ' with '%20'
	public static String ReplaceSpaceWithEncode(String input)
	{
		input = input.trim();
		
		int numOfSpaces = 0;
		for(int i=0; i<input.length(); ++i) {
			if (input.charAt(i) == ' ') {
				numOfSpaces++;
			}
		}
		
		int newSize = input.length() + 2 * numOfSpaces;
		char[] newInput = new char[newSize];
		
		int index = input.length()-1;
		int newInputIndex = newSize-1;
		while(index >= 0)
		{
			if (input.charAt(index) != ' ')
			{
				newInput[newInputIndex--] = input.charAt(index--); 
				
			}
			else
			{
				// %20
				newInput[newInputIndex--] = '0';
				newInput[newInputIndex--] = '2';
				newInput[newInputIndex--] = '%';
				index--;
			}
		}
		return new String(newInput);
	}

	public static void main(String[] args) {
		String str = "abc d e f";
		char[] arr = new char[str.length() + 3 * 2 + 1];
		for (int i = 0; i < str.length(); i++) {
			arr[i] = str.charAt(i);
		}
		String output = ReplaceSpaceWithEncode(str);	
		System.out.println(str + " = " + output);

	}

}
