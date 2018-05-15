package StringProblems;

public class StrStr {
	
	// O(mn)
	public static int Find(String needle, String haystack)
	{
		for (int i=0; ; i++)
		{
			for (int j=0; ; j++)
			{
				if (j == needle.length())
				{
					return i;
				}
				
				if (i+j == haystack.length())
				{
					return -1;
				}
				
				if (needle.charAt(j) != haystack.charAt(i+j))
				{
					break;
				}				
			}
		}
		
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub

		String needle = "needle";
		String haystack = "In this haystack is a tiny needle of no significance";
		System.out.println("Should find needle at " + Find(needle, haystack));
		
		needle = "needle";
	    haystack = "In this haystack is a tiny needl of no significance";
		System.out.println("Should not find needle at " + Find(needle, haystack));
	}

}
