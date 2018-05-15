/*
 Given an input string, reverse the string word by word.
 
 For example,
 Given s = "the sky is blue",
 return "blue is sky the".
 
 Update (2015-02-12):
 For C programmers: Try to solve it in-place in O(1) space.
 
 click to show clarification.
 
 Hide Company Tags Microsoft Snapchat Apple Bloomberg Yelp
 Hide Tags String
 Hide Similar Problems (M) Reverse Words in a String II

 */

class Solution {
public:
    void reverseWords(string &s) {
        if (s.length() == 0) return;
        
        // trim leading spaces
        int start = 0;
        while (start < s.length() && s[start] == ' ') start++;
        if (start > 0)
        {
            s.erase(s.begin(), s.begin()+start);
        }
        if (s.length() == 0) return;
        
        
        // trim trailing spaces
        size_t end = s.length()-1;
        while (s[end] == ' ') end--;
        if (end < s.length()-1)
        {
            s.erase(s.begin()+end+1, s.end());
        }
        
        if (s.length() == 1) return;
        
        // first reversal
        reverse(s, 0, s.length()-1);
        
        end = s.length();
        // start at front and reverse each word.
        int i=0;
        while (i < end)
        {
            if (s[i] != ' ')
            {
                // start of word, find the end of the word and reverse it
                int j = i;
                while (j < end && s[j] != ' ') j++;
                reverse(s, i, j-1);
                i = j;
            }
            else
            {
                // space.  Look ahread to see if next index is a space.  If so, shift all elements down
                int j = i+1;
                if (j < end && s[j] == ' ')
                {
                    // shift all elements down and derement end
                    while (j < end-1)
                    {
                        s[j] = s[j+1];
                        j++;
                    }
                    end--;
                }
                else
                {
                    // just a single space.
                    i++;
                }
            }
        }
        
        s = s.substr(0, end);
    }
    
    
    void reverse(string& s, int start, int end)
    {
        while (start < end)
        {
            swap(s[start], s[end]);
            start++;
            end--;
        }
    }
};