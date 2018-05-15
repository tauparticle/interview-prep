//
//  Reverse_Words_In_String.h
//  Interview_Prep_Native
//
//  Created by Isaiah Paradiso on 5/28/16.
//  Copyright © 2016 poot industries. All rights reserved.
//

#ifndef Reverse_Words_In_String_h
#define Reverse_Words_In_String_h


#endif /* Reverse_Words_In_String_h */

class ReverseWords {
public:
    void reverseWords(std::string &s) {
        
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
        //for (int i=0; i<end; ++i)
        int i=0;
        while (i < end)
        {
            if (s[i] != ' ')
            {
                // start of word, find the end of hte word and reverse it
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
                    while (j < end-1)
                    {
                        s[j] = s[j+1];
                        j++;
                    }
                    end--; // decrement end
                }
                else
                {
                    i++;
                }
            }
        }
        
        s = s.substr(0, end);
    }
    
    
    void reverse(std::string& s, size_t start, size_t end)
    {
        while (start < end)
        {
            std::swap(s[start], s[end]);
            start++;
            end--;
        }
    }
};
