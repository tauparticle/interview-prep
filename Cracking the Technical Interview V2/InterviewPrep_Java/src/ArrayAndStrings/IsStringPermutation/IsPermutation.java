package ArrayAndStrings.IsStringPermutation;

import java.lang.String;
import java.util.Arrays;

public class IsPermutation {
	
	private static String sort(String a)
	{
		char[] a_arr = a.toCharArray();
		Arrays.sort(a_arr);
		return new String(a_arr);
	}
	
	public static boolean IsPermutationEasy(String a, String b)
	{
		if (a.length() != b.length()) return false;
		return sort(a).equals(sort(b));
	}
	
	public static boolean IsPermutationEfficient(String s, String t)
	{
		if (s.length() != t.length()) {
			return false;
		}
		
		int[] letters = new int[256];
		 
		char[] s_array = s.toCharArray();
		for (char c : s_array) { // count number of each char in s.
			letters[c]++;  
		}
		  
		for (int i = 0; i < t.length(); i++) {
			int c = (int) t.charAt(i);
		    if (--letters[c] < 0) {
		    	return false;
		    }
		}
		  
		return true;
	}

	public static void main(String[] args) {
		String[][] pairs = {{"apple", "papel"}, {"carrot", "tarroc"}, {"hello", "llloh"}, {"aabbcc", "aabbcc"}};
		for (String[] pair : pairs) {
			String word1 = pair[0];
			String word2 = pair[1];
			boolean anagram = IsPermutationEasy(word1, word2);
			boolean anagram2 = IsPermutationEfficient(word1, word2);
			System.out.println(word1 + ", " + word2 + ": " + anagram + " : " + anagram2);
		}
	}

}
