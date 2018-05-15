package StringProblems;

import java.util.*;

public class NormalizePath {
	
	public static String normalize(String path) {
		
		Stack<String> s = new Stack<String>();
		StringBuilder sb = new StringBuilder();
		int prev = 0;
		int i = findNext(path, '/', prev);
		while (i <= path.length()) {
			String temp = path.substring(prev, i);
			if (temp.equalsIgnoreCase("..") && !s.isEmpty()) {
				s.pop();
			}
			else if (!temp.equalsIgnoreCase(".")) {
				s.push(temp);
			}
			
			prev = i+1;
			i = findNext(path, '/', prev);			
		}
		
		if (!s.isEmpty()) {
			String token = s.peek();
			s.pop();
			BuildPath(token, s, sb);
		}
		return sb.toString();
		
		
	}
	
	private static int findNext(String str, char c, int start)
	{
		while (start < str.length()) {
			if (str.charAt(start) == c) {
				return start;
			}
			
			start++;
		}
		return start;
	}
	
	private static void BuildPath(String token, Stack<String> tokens, StringBuilder sb)
	{	 
		if (token == null) { 
			return;
		}
		 if (!tokens.isEmpty()) {
			 String top = tokens.peek();
			 tokens.pop();
			 BuildPath(top, tokens, sb);
		 }
		 
		 sb.append("/");
		 sb.append(token);		
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub

		String path = "a/b/c/d/../../../../f/text.log";
		System.out.println(path + " -> " + normalize(path));
	}

}
