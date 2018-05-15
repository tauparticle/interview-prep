/*
Given a string, determine if a permutation of the string could form a palindrome.

For example,
"code" -> False, "aab" -> True, "carerac" -> True.

Hints
1) Consider the palindromes of odd vs even length. What difference do you notice?
2) Count the frequency of each character.
3) If each character occurs even number of times, then it must be a palindrome. How about character which occurs odd number of times?
 
*/

// s should have 0 or 1 odd number character
public boolean canPermutePalindrome(String s) {
    Map<Character, Integer> map = new HashMap<>();
    for(int i=0; i<s.length(); i++) 
    {
        char c = s.charAt(i);
        if (!map.containsKey(c))
        {
            map.put(c, 1);
        }
        else
        {
            map.put(c, map.get(c)+1);
        }
    }
    int count = 0;
    for (int v: map.values())
    {
        if (v%2==1)
        {
            count++;
        }
    }
    return count == 1 || count == 0;
}