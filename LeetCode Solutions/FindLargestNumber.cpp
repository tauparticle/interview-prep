
/*
 Given a list of non negative integers, arrange them such that they form the largest number.
 
 For example, given [3, 30, 34, 5, 9], the largest formed number is 9534330.
 
 Note: The result may be very large, so you need to return a string instead of an integer.
 */


class Solution {
    public:
    string largestNumber(vector<int> &num) {
        
        sort(num.begin(), num.end(), compareFunctionNoString);
        
        stringstream s;
        bool hasNonZero = false;
        
        for(int i=0; i<num.size(); ++i)
        {
            if (num[i] != 0) hasNonZero = true;
            s << num[i];
        }
        
        return (!hasNonZero) ? "0" : s.str();
        
    }
    
    bool static compareFunctionNoString(int i, int j) {
        unsigned int iLen = 10;
        unsigned int jLen = 10;
        
        // compute base of i
        while (i / iLen > 0) {
            iLen *= 10;
        }
        
        // compute base of j
        while (j / jLen > 0) {
            jLen *= 10;
        }
        
        // base * number + other number.  Use long to help avoid overflow
        long iN = i * jLen + j;
        long jN = j * iLen + i;
        
        return iN > jN;
    }
};