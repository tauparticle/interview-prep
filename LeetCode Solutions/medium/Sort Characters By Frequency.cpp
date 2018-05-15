/*451. Sort Characters By Frequency   QuestionEditorial Solution  My Submissions
Total Accepted: 5972
Total Submissions: 12126
Difficulty: Medium
Contributors: stickypens
Given a string, sort it in decreasing order based on the frequency of characters.

Example 1:

Input:
"tree"

Output:
"eert"

Explanation:
'e' appears twice while 'r' and 't' both appear once.
So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.
Example 2:

Input:
"cccaaa"

Output:
"cccaaa"

Explanation:
Both 'c' and 'a' appear three times, so "aaaccc" is also a valid answer.
Note that "cacaca" is incorrect, as the same characters must be together.
Example 3:

Input:
"Aabb"

Output:
"bbAa"

Explanation:
"bbaA" is also a valid answer, but "Aabb" is incorrect.
Note that 'A' and 'a' are treated as two different characters.
Hide Company Tags Amazon Google
Hide Tags Hash Table Heap
Hide Similar Problems (M) Top K Frequent Elements

*/

class Solution {

public:
    string frequencySort(string s) {
        
        unordered_map<char, int> charCounts;
        for (char c : s) 
        {
            charCounts[c]++;
        }
        
        vector<CharNode> pairs;
        for (auto iter = charCounts.begin(); iter != charCounts.end(); ++iter) {
            pairs.push_back({iter->first, iter->second});
        }
        sort(pairs.begin(), pairs.end(), CharNodeSort());
        
        ostringstream oss;
        for (auto pair : pairs)
        {
            for (int i=0; i<pair.count; ++i)
            {
                oss << pair.ch;
            }
        }
        return oss.str();
    }
    
    struct CharNode
    {
        char ch;
        int count;
    };
    
    struct CharNodeSort 
    {
        bool operator() (const CharNode& a, const CharNode& b)
        {
            return a.count > b.count;
        }
    };
    

};