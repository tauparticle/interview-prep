/* Assume you have an array of length n initialized with all 0's and are given k update operations.

Each operation is represented as a triplet: [startIndex, endIndex, inc] which increments each element of subarray A[startIndex ... endIndex] (startIndex and endIndex inclusive) with inc.

Return the modified array after all k operations were executed.

Example:

Given:

    length = 5,
    updates = [
        [1,  3,  2],
        [2,  4,  3],
        [0,  2, -2]
    ]

Output:

    [-2, 0, 3, 5, 3]
Explanation:

Initial state:
[ 0, 0, 0, 0, 0 ]

After applying operation [1, 3, 2]:
[ 0, 2, 2, 2, 0 ]

After applying operation [2, 4, 3]:
[ 0, 2, 5, 5, 3 ]

After applying operation [0, 2, -2]:
[-2, 0, 3, 5, 3 ]
*/


// the trick here is to just record the final sum of the beginning indicies, and then negate the sum for each end+1 indicies.  Then you can do a range sum of the whole array in a single pass.  
class Solution {
public:
    vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
        vector<int> arr(length+1, 0);
        
        for (auto& update : updates)
        {
            int start = update[0];
            int end = update[1];
            int inc = update[2];
            
            arr[start] += inc;
            arr[end+1] += -inc;
        }
        
        int carry = 0;
        for (int i=0; i<arr.size(); ++i)
        {
            arr[i] += carry;
            carry = arr[i];
        }
        
        arr.pop_back();
        
        return arr;
    }
};