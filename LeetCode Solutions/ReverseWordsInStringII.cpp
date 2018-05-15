
/*
 Given an input string, reverse the string word by word. A word is defined as a sequence of non-space characters.
 
 The input string does not contain leading or trailing spaces and the words are always separated by a single space.
 
 For example,
 Given s = "the sky is blue",
 return "blue is sky the".
 
 Could you do it in-place without allocating extra space?
 
 Related problem: Rotate Array
 
 Hide Company Tags Amazon Microsoft Uber
 Hide Tags String
 Hide Similar Problems (M) Reverse Words in a String (E) Rotate Array

 */

class Solution {
public:
    void reverseWords(std::string &s)
    {
        if (s.length() < 1) return;
        
        reverse(s, 0, s.length()-1);
        
        int current = (int)s.length()-1;
        while (current >= 0)
        {
            if (s[current] != ' ')
            {
                size_t end = current;
                
                while(current > 0 && s[current] != ' ' && s[current-1] != ' ') current--;
                reverse(s, current, end);
                current--;
            }
            else
            {
                current--;
            }
        }
    }
    
    void reverse(std::string& s, size_t start, size_t end)
    {
        while (start < end)
        {
            std::swap(s[start], s[end]);
            start++, end--;
        }
    }
};