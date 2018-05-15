//
//  Longes_Palindrome_String.h
//  Interview_Prep_Native
//
//  Created by Isaiah Paradiso on 6/1/16.
//  Copyright © 2016 poot industries. All rights reserved.
//

#ifndef Longes_Palindrome_String_h
#define Longes_Palindrome_String_h


#endif /* Longes_Palindrome_String_h */

class LongestPalindrome {
public:
    std::string longestPalindrome(std::string s)
    {
        int start = 0, end = 0;
        for (int i = 0; i < s.length(); i++)
        {
            int len1 = expandAroundCenter(s, i, i);
            int len2 = expandAroundCenter(s, i, i + 1);
            int len = std::max(len1, len2);
            if (len > end - start)
            {
                start = i - (len - 1) / 2;
                end = i + len / 2;
            }
        }
        return s.substr(start, end-start + 1);
    }
    
    int expandAroundCenter(std::string& s, int left, int right)
    {
        int L = left, R = right;
        while (L >= 0 && R < s.length() && s[L] == s[R])
        {
            L--;
            R++;
        }
        return R - L - 1;
    }
};