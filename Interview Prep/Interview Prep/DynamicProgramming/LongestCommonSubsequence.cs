using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Interview_Prep
{
    class LongestCommonSubsequence
    {
        public static void Test()
        {
     
		string a = "ABCDEF";
		string b = "ABC23F";
        Console.WriteLine("Longest Common Subsequence of " + a + "+" + b + " =" + LCSImpl(a, b));
        a = "abc";
        b = "aec";
        Console.WriteLine("Longest Common Subsequence of " + a + "+" + b + " =" + LCSImpl(a, b));

        a = "HUMAN";
        b = "CHIMPANZEE";
        Console.WriteLine("Longest Common Subsequence of " + a + "+" + b + " =" + LCSImpl(a, b));
        }

        // Quadradic runtime O(xy).  If x and LCSImpl y are similar length, then it's O(n^2) runtime and space
        public static string LCSImpl(string x, string y)
        {
	        int M = x.Length;
	        int N = y.Length;

	        // opt[i][j] = length of LCS of x[i..M] and y[j..N]
	        int[,] lcs = new int[M+1, N+1];

	        // compute length of LCS and all subproblems via dynamic programming
	        for (int i = M-1; i >= 0; i--) {
	            for (int j = N-1; j >= 0; j--) {
	                if (x[i] == y[j])
                        lcs[i, j] = lcs[i + 1, j + 1] + 1;
	                else
                        lcs[i, j] = Math.Max(lcs[i + 1, j], lcs[i, j + 1]);
	            }
	        }

	        // recover LCS itself and print it to standard output
	        StringBuilder sb = new StringBuilder();
	        int a = 0;
            int b = 0;
	        while(a < M && b < N) 
            {
                // if they're equal, append to the sb, and advance both pointers
	            if (x[a] == y[b]) 
                {
	                sb.Append(x[a]);
	                a++;
	                b++;
	            }
                // else
                else if (lcs[a + 1, b] >= lcs[a, b + 1])
                {
                    a++;
                }
                else
                {
                    b++;
                }
	        }
	        return sb.ToString();

	    }
    }
}
