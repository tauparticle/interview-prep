class Solution {
public:
    // solution is to use binary search for O(log n).
    int findMin(vector<int> &num) {
        int start = 0;
        int end = num.size() - 1;
        while(start < end) {
            int mid = (start + end) / 2;
            if(num[mid] >= num[end])
            {
                // rotation index is in the second half
                start = mid;
                if(end-mid == 1) return num[end];
            }
            else if(num[start] >= num[mid])
            {
                // rotation index is in the first half
                end = mid;
                if(mid-start == 1) return num[mid];
            }
            else
            {
                // we're sorted.  Return the first element
                return num[start];
            }
        }
        // we have convered at the end, and the rotation is the last element
        return num[end];
    }
};