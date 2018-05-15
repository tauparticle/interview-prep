//Given an array of size n, find the majority element. The majority element is the element that appears more 
// than n/2 times. You may assume that the array is non-empty and the majority element always exist in the array.

// this solution takes O(n) time and O(n) space. 
// other solutions:  
// 1) Sorting:  O(n log n).  Sort the array.  The middle n/2 element is the majority element.
// 2) Moore voting algorithm: O(n) -  We maintain a current candidate and a counter initialized to 0.  As we iterate the array
//    We look at the current element x: 
//           1) if the counter is 0, we set current candidate to x and counter to 1.    
//           2) if the counter is not 0, we increment or decrement the counter based on whether x is the current candidate.
//    After one pass, the current cadidate is the majority element.  

class Solution {
public:
    int majorityElement(vector<int> &num) {
        map<int, int> counts;
        for (int i=0; i<num.size(); ++i)
        {
            counts[num[i]]++;
        }
        
        int majorityThreshold = num.size() / 2;
        map<int, int>::iterator iter;
        for (iter = counts.begin(); iter != counts.end(); ++iter) 
        {
            if (iter->second > majorityThreshold) {
                return iter->first;
            }
        }
        
        return -1;  // or throw
    }
};