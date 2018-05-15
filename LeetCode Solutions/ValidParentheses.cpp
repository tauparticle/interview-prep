
// Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
//
//The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
 

// initial solution of O(n)
class Solution {
public:
    bool isValid(string s) {
        map<char, char> mapping;
        mapping['('] = ')';
        mapping['{'] = '}';
        mapping['['] = ']';
        stack<char> q;
        
        for(int i=0; i<s.size(); ++i)
        {
            bool insert = true;
            if (q.size() > 0)
            {
                char c = s[i];
                char t = q.top();
                if (c == mapping[t])
                {
                    q.pop();
                    insert = false;
                }
            }
            
            if (insert)
            {
                q.push(s[i]);
            }
        }
        
        return (q.size() == 0);
    }
};

// there's some ways squeeze some faster perf using ascii subtraction and early terminations rather than the map above

class Solution {
public:
    bool isValid(string s) {
        stack<char> left;
        for(int i=0;i<s.length();i++)
        {
            char ch=s[i];
            if(ch=='('||ch=='['||ch=='{')
            {
                left.push(ch);
                continue;
            }
            //else ch==),],}
            if(left.empty())
                return false;
            //now left!=empty ch = ) ] }
            if(ch-left.top()<=2)//match via ascii
                left.pop();//here cause WA,else means nomatch must return false
            else
                return false;
        }
        return left.empty();
    }
};