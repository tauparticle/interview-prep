/*
 The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)
 
 P   A   H   N
 A P L S I I G
 Y   I   R
 And then read line by line: "PAHNAPLSIIGYIR"
 Write the code that will take a string and make this conversion given a number of rows:
 
 string convert(string text, int nRows);
 convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".
 Hide Tags String

 */


class Solution {
public:
    string convert(string s, int numRows) {
        vector<string> rows(numRows, "");
        
        if (numRows == 1)
        {
            return s;
        }
        int row = 0;
        int incVal = 1;
        bool traversing = false;
        
        for (int i=0; i<s.length(); ++i)
        {
            rows[row] += s[i];
            row += incVal;
            
            if (row == numRows-1 || row == 0)
            {
                incVal *= -1;
            }
        }
        
        string str;
        for (int i=0; i<numRows; ++i)
        {
            str.append(rows[i]);
        }
        
        return str;
        
    }
    
};