/*
 448. Find All Numbers Disappeared in an Array   QuestionEditorial Solution  My Submissions
 Total Accepted: 2274
 Total Submissions: 3560
 Difficulty: Easy
 Contributors: yuhaowang001
 Given an array of integers where 1 ≤ a[i] ≤ n (n = size of array), some elements appear twice and others appear once.
 
 Find all the elements of [1, n] inclusive that do not appear in this array.
 
 Could you do it without extra space and in O(n) runtime? You may assume the returned list does not count as extra space.
 
 Example:
 
 Input:
 [4,3,2,7,8,2,3,1]
 
 Output:
 [5,6]
 Hide Company Tags Google
 Hide Tags Array
 Hide Similar Problems (H) First Missing Positive (M) Find All Duplicates in an Array
*/

class Solution {
public:
    
    /*
     The idea is simple, if nums[i] != i + 1 and nums[i] != nums[nums[i] - 1], then we swap nums[i] with nums[nums[i] - 1], for example, nums[0] = 4 and nums[3] = 7, then we swap nums[0] with nums[3]. So In the end the array will be sorted and if nums[i] != i + 1, then i + 1 is missing.
     The example run as follows
     
     [4,3,2,7,8,2,3,1]
     [7,3,2,4,8,2,3,1]
     [3,3,2,4,8,2,7,1]
     [2,3,3,4,8,2,7,1]
     [3,2,3,4,8,2,7,1]
     [3,2,3,4,1,2,7,8]
     [1,2,3,4,3,2,7,8]
     Since every swap we put at least one number to its correct position, the time is O(n)
     
     */
    
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        
        for (int i=0; i<nums.size(); ++i)
        {
            while (nums[i] != i+1 && nums[i] != nums[nums[i] - 1])
            {
                int tmp = nums[i];
                nums[i] = nums[tmp - 1];
                nums[tmp - 1] = tmp;
            }
        }
        
        vector<int> missing;
        for (int i=0; i<nums.size(); ++i)
        {
            if (nums[i] != i+1)
            {
                missing.push_back(i+1);
            }
        }
        return missing;
        
    }
};
