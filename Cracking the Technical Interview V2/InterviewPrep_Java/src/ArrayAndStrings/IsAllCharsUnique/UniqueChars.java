package ArrayAndStrings.IsAllCharsUnique;

import java.lang.String;

public class UniqueChars {
	
	public static boolean AreCharsUnique(String str)
	{
		if (str == null ) return false;
		if (str.length() < 2) {
			return true;
		}
		
		boolean[] charMap = new boolean[256];
		for(int i=0; i<str.length(); ++i)
		{
			int index = (int)str.charAt(i);
			if (!charMap[index]){
				charMap[index] = true;
			}
			else {
				return false;
			}
		}
		
		return true;
	}
	

	public static void main(String[] args) {
		
		System.out.println("dfewwsd --> " + AreCharsUnique("dfewwsd"));
		System.out.println("as --> " + AreCharsUnique("as"));
		System.out.println("isisldi --> " + AreCharsUnique("isisldi"));
		System.out.println("a --> " + AreCharsUnique("a"));
		System.out.println("null --> " + AreCharsUnique(null));
		System.out.println("hjsaklwiqo --> " + AreCharsUnique("hjsaklwiqo"));
		System.out.println("apple --> " + AreCharsUnique("apple"));

	}

}
