/* The question is given a string of characters, return the number of tuple pairs where
 index: x < y && s[x] < s[y].
 
 You just need to return the number of tuple pairs.  Do this is O(n) time.
*/

package moderate;

public class CountNumberOfTuple {
    
    public static int countNumberOfTuples(String str)
    {
        if (str == null || str.length() < 2)
        {
            return 0;
        }
        
        // assuming lower case alpha characters only
        int[] charCounts = new int[26];
        
        for (char c : str.toCharArray()) {
            charCounts[c - 'a']++;
        }
        
        char ch = str.charAt(0);
        int totalTuples = computeTuplesFromChar(charCounts, ch);
        tryDecrementCharCount(charCounts, ch);
        for (int i=1; i<str.length(); ++i)
        {
            ch = str.charAt(i);
            totalTuples += computeTuplesFromChar(charCounts, ch);
            tryDecrementCharCount(charCounts, ch);
        }
        return totalTuples;
    }
    
    private static void tryDecrementCharCount(int[] charCounts, char c)
    {
        int idx = c - 'a';
        if (charCounts[idx] > 0)
        {
            charCounts[idx]--;
        }
    }
    
    private static int computeTuplesFromChar(int[] charCounts, char c)
    {
        int idx = c - 'a';
        int count = 0;
        for (int i=idx+1; i<charCounts.length; ++i)
        {
            count += charCounts[i];
        }
        return count;
    }
    
    public static void main(String[] args) {
        // TODO Auto-generated method stub
        
        System.out.println("aababacba = " + countNumberOfTuples("aababacba"));
        System.out.println("ababab = " + countNumberOfTuples("ababab"));
        System.out.println("abcd = " + countNumberOfTuples("abcd"));
        System.out.println("a = " + countNumberOfTuples("a"));
        System.out.println(" = " + countNumberOfTuples(""));
        System.out.println("bc = " + countNumberOfTuples("bc"));
    }
    
}
