/*
153. Find Minimum in Rotated Sorted Array   QuestionEditorial Solution  My Submissions
Total Accepted: 118590
Total Submissions: 311045
Difficulty: Medium
Contributors: Admin
Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

Find the minimum element.

You may assume no duplicate exists in the array.

Hide Company Tags Microsoft
Hide Tags Array Binary Search
Hide Similar Problems (H) Search in Rotated Sorted Array (H) Find Minimum in Rotated Sorted Array II

*/

class Solution {
public:

    // two solutions.  One using STL and the other using modified binary search
    int findMin2(vector<int>& nums) {
    auto it = std::is_sorted_until(nums.begin(), nums.end());
        if(it == nums.end()) return nums[0];
        else                 return *it;
    }
    
    int findMin(vector<int>& nums) {
        int begin = 0;
        int end = nums.size()-1;
        
        while (begin < end && nums[begin] > nums[end])
        {
            int mid = begin + (end - begin) / 2;
            if (nums[mid] < nums[end])
            {
                end = mid;
            }
            else
            {
                begin = mid + 1;
            }
        }
        return nums[begin];
    }
};