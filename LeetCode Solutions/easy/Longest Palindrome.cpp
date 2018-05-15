/*
 Given a string which consists of lowercase or uppercase letters, find the length of the longest palindromes that can be built with those letters.
 
 This is case sensitive, for example "Aa" is not considered a palindrome here.
 
 Note:
 Assume the length of given string will not exceed 1,010.
 
 Example:
 
 Input:
 "abccccdd"
 
 Output:
 7
 
 Explanation:
 One longest palindrome that can be built is "dccaccd", whose length is 7.
 Hide Company Tags Google
 Hide Tags Hash Table
 Hide Similar Problems (E) Palindrome Permutation

 */

class Solution {
public:
    
    // the trick here is to count how many odd groups of chars exist and subtract them from the length.
    // Evens can be used once.  Odds cannot, except for just one of them (i.e. the middle element of odd length)
    int longestPalindrome(string s) {
        vector<int> counts(256, 0);
        int odds = 0;
        for (char c : s)
        {
            counts[c]++;
        }
        
        for (int i : counts)
        {
            odds += (i & 1) ? 1 : 0;
        }
        int selectSingleOdd = (odds > 0) ? 1 : 0;
        return s.length() - odds + selectSingleOdd;
    }
};
