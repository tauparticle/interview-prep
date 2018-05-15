/* Rotate an array of n elements to the right by k steps.

For example, with n = 7 and k = 3, the array [1,2,3,4,5,6,7] is rotated to [5,6,7,1,2,3,4].

Note:
Try to come up as many solutions as you can, there are at least 3 different ways to solve this problem. 
Could you do it in-place with O(1) extra space?*/

class Solution {
public:
    void rotate(int nums[], int n, int k) 
    {
        // O(n) time and O(1) space
        
        // trick here is reverse the entire array
        reverse(nums, 0, n-1);
        // then reverse just 0-k
        reverse(nums, 0, k%n-1);
        // finally reverse k-n.  This magically gives you the rotated array
        reverse(nums, k%n, n-1); 
    }
    
    void reverse(int num[], int left, int right) 
    {
        while (left < right) {
            int temp = num[left];
            num[left] = num[right];
            num[right] = temp;
            left++; 
            right--;
        }
    }
};