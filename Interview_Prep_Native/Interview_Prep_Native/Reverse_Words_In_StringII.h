//
//  Reverse_Words_In_StringII.h
//  Interview_Prep_Native
//
//  Created by Isaiah Paradiso on 5/28/16.
//  Copyright © 2016 poot industries. All rights reserved.
//

#ifndef Reverse_Words_In_StringII_h
#define Reverse_Words_In_StringII_h


#endif /* Reverse_Words_In_StringII_h */

class ReverseWords2 {
public:
    void reverseWords(std::string &s) {
        
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