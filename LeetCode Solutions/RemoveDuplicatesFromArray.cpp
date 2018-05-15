/*
 Given an array and a value, remove all instances of that value in place and return the new length.
 
 Do not allocate extra space for another array, you must do this in place with constant memory.
 
 The order of elements can be changed. It doesn't matter what you leave beyond the new length.
 
 Example:
 Given input array nums = [3,2,2,3], val = 3
 
 Your function should return length = 2, with the first two elements of nums being 2.
 
 Show Hint
 Hide Tags Array Two Pointers
 Hide Similar Problems (E) Remove Duplicates from Sorted Array (E) Remove Linked List Elements (E) Move Zeroes

 */

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        
        int count = 0;
        int size = (int)nums.size();
        for (int i=0; i<size; ++i)
        {
            if (nums[i] == val)
            {
                std::swap(nums[i], nums[nums.size()-count-1]);
                size--;
                i--;
                count++;
            }
        }
        
        return (int)nums.size() - count;
    }
};