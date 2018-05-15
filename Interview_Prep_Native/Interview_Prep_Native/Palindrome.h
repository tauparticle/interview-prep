//
//  Shortest_Palindrome.h
//  Interview_Prep_Native
//
//  Created by Isaiah Paradiso on 10/2/16.
//  Copyright © 2016 poot industries. All rights reserved.
//

#ifndef Shortest_Palindrome_h
#define Shortest_Palindrome_h

using namespace std;

class Palindrome
{
public:
    static string shortestPalindrome(string s)
    {
        size_t len = s.length();
        string rev = s;
        reverse(rev.begin(), rev.end());
        
        int i=len;
        for (; i >= 0; i--)
        {
            //string s_sub = s.substr(0, i);
            //string rev_sub = rev.substr(len-i);
            //if (s_sub == rev_sub)
            if (quickCompare(s, rev, 0, i, len-i, len))
            {
                break;
            }
        }
        
        for(int c=len-i-1; c >= 0; c--)
        {
           s = rev[c] + s;
        }
        return s;
    }
    
    static bool quickCompare(string& a, string& b, int a_start, int a_end, int b_start, int b_end)
    {
        int i = a_start;
        int j = b_start;
        int a_len = a_end - a_start;
        int b_len = b_end - b_start;
        if (a_len != b_len)
        {
            return false;
        }
        while (i < a_end && j < b_end)
        {
            if (a[i++] != b[j++])
            {
                return false;
            }
        }
        
        return true;
    }
    
};


#endif /* Shortest_Palindrome_h */
