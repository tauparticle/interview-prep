
/*
249. Group Shifted Strings   QuestionEditorial Solution  My Submissions
Total Accepted: 15497
Total Submissions: 42826
Difficulty: Easy
Contributors: Admin
Given a string, we can "shift" each of its letter to its successive letter, for example: "abc" -> "bcd". We can keep "shifting" which forms the sequence:

"abc" -> "bcd" -> ... -> "xyz"
Given a list of strings which contains only lowercase alphabets, group all strings that belong to the same shifting sequence.

For example, given: ["abc", "bcd", "acef", "xyz", "az", "ba", "a", "z"], 
A solution is:

[
  ["abc","bcd","xyz"],
  ["az","ba"],
  ["acef"],
  ["a","z"]
]
Hide Company Tags Google Uber
Hide Tags Hash Table String
Hide Similar Problems (M) Group Anagrams


*/
class Solution {
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        
        unordered_map<string, vector<string>> shiftMap;
        
        for (auto str : strings)
        {
            string key = encode(str);
            auto& list = shiftMap[key];
            list.push_back(str);
        }
        
        vector<vector<string>> result;
        for (auto iter = shiftMap.begin(); iter != shiftMap.end(); ++iter)
        {
            auto& list = iter->second;
            
            result.push_back(list);
        }
        return result;
        
    }
    
    string encode(const string& str)
    {
        string KEY = "";
        for(int i = 1; i < str.size(); ++i)
        {
            // need to account for a->z wrap around ordering.
            KEY += to_string(str[i] - str[i-1] < 0 ? str[i] - str[i-1] + 26 : str[i] - str[i-1]) + ".";
        }
        return KEY;
    }
};