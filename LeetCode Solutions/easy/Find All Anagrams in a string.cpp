/*
38. Find All Anagrams in a String   QuestionEditorial Solution  My Submissions
Total Accepted: 4841
Total Submissions: 14609
Difficulty: Easy
Contributors: Stomach_ache
Given a string s and a non-empty string p, find all the start indices of p's anagrams in s.

Strings consists of lowercase English letters only and the length of both strings s and p will not be larger than 20,100.

The order of output does not matter.

Example 1:

Input:
s: "cbaebabacd" p: "abc"

Output:
[0, 6]

Explanation:
The substring with start index = 0 is "cba", which is an anagram of "abc".
The substring with start index = 6 is "bac", which is an anagram of "abc".
Example 2:

Input:
s: "abab" p: "ab"

Output:
[0, 1, 2]

Explanation:
The substring with start index = 0 is "ab", which is an anagram of "ab".
The substring with start index = 1 is "ba", which is an anagram of "ab".
The substring with start index = 2 is "ab", which is an anagram of "ab".
Hide Company Tags Amazon
Hide Tags Hash Table
Hide Similar Problems (E) Valid Anagram
*/

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        
        int windowSize = p.length()-1;
        string p_hash = hash(p, 0, p.length()-1);
        
        vector<int> output;
        int tail = 0;
        int head = windowSize;
        
        while (head < s.size())
        {
            string h = hash(s, tail, head);
            if (h == p_hash)
            {
                output.push_back(tail);
            }
            tail++;
            head++;
        }
        
        return output;
        
    }
    
    string hash(string& str, int start, int end)
    {
        int counts[26] = {0};
        for (int i=start; i<=end; ++i)
        {
            counts[str[i] - 'a']++;
        }
        
        string hash;
        for (int i=0; i<26; ++i)
        {
            hash += to_string(counts[i]);
        }
        
        return hash;
    }
};