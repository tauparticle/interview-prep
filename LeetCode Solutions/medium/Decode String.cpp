/*
394. Decode String   QuestionEditorial Solution  My Submissions
Total Accepted: 10643
Total Submissions: 26907
Difficulty: Medium
Contributors: Admin
Given an encoded string, return it's decoded string.

The encoding rule is: k[encoded_string], where the encoded_string inside the square brackets is being repeated exactly k times. Note that k is guaranteed to be a positive integer.

You may assume that the input string is always valid; No extra white spaces, square brackets are well-formed, etc.

Furthermore, you may assume that the original data does not contain any digits and that digits are only for those repeat numbers, k. For example, there won't be input like 3a or 2[4].

Examples:

s = "3[a]2[bc]", return "aaabcbc".
s = "3[a2[c]]", return "accaccacc".
s = "2[abc]3[cd]ef", return "abcabccdcdcdef".
Hide Company Tags Google
Hide Tags Depth-first Search Stack

*/


class Solution {
public:
    string decodeString(string s) 
    {
        string str = "";
        stack<string> stack_str;
        stack<int> stack_num;
        int num = 0;

        for(int i=0; i<s.length(); i++)
        {
            char c = s[i];
            if(c =='[')
            {
                stack_str.push(str);
                str = "";
            }
            else if(c ==']')
            {
                string temp = stack_str.top();
                stack_str.pop();
                num = stack_num.top();
                stack_num.pop();
                for(int t=0; t<num; t++)
                {
                    temp.append(str);
                }
                str = temp;
            }
            else if(isdigit(c))
            {
                num = 0;
                while(isdigit(c))
                {
                    num = num*10+(c-'0');
                    i++;
                    c = s[i];
                }
                stack_num.push(num);
                i--;
            }
            else 
            { 
                str += c;
            }
        }
        return str;
    }
};