package Question1_1;

public class Question {

	public static boolean isUniqueChars(String str) {
		int checker = 0;
		for (int i = 0; i < str.length(); ++i) {
			int val = str.charAt(i) - 'a';
			if ((checker & (1 << val)) > 0) return false;
			checker |= (1 << val);
		}
		return true;
	}
	
	public static boolean isUniqueChars2(String str) {
		boolean[] char_set = new boolean[256];
		for (int i = 0; i < str.length(); i++) {
			int val = str.charAt(i);
			if (char_set[val]) return false;
			char_set[val] = true;
		}
		return true;
	}
	
	 public static String LongestCommonSubsequence(String x, String y) {
	        int M = x.length();
	        int N = y.length();

	        // opt[i][j] = length of LCS of x[i..M] and y[j..N]
	        int[][] opt = new int[M+1][N+1];

	        // compute length of LCS and all subproblems via dynamic programming
	        for (int i = M-1; i >= 0; i--) {
	            for (int j = N-1; j >= 0; j--) {
	                if (x.charAt(i) == y.charAt(j))
	                    opt[i][j] = opt[i+1][j+1] + 1;
	                else 
	                    opt[i][j] = Math.max(opt[i+1][j], opt[i][j+1]);
	            }
	        }

	        // recover LCS itself and print it to standard output
	        StringBuilder sb = new StringBuilder();
	        int i = 0, j = 0;
	        while(i < M && j < N) {
	            if (x.charAt(i) == y.charAt(j)) {
	                sb.append(x.charAt(i));
	                i++;
	                j++;
	            }
	            else if (opt[i+1][j] >= opt[i][j+1]) i++;
	            else                                 j++;
	        }
	        return sb.toString();

	    }
	
	public static void main(String[] args) {
		String[] words = {"abcde", "hello", "apple", "kite", "padle"};
		for (String word : words) {
			System.out.println(word + ": " + isUniqueChars(word) + " " + isUniqueChars2(word));
		}
		String a = "ABCDEF";
		String b = "ABC2F3";
		System.out.println("Longest Common Subsequence of " + a + "+" + b + " is");

		System.out.println(LongestCommonSubsequence(a, b));
	}

}
