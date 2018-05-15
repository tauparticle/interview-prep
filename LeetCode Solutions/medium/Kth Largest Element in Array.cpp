/*
 Find the kth largest element in an unsorted array. Note that it is the kth largest element in the sorted order, not the kth distinct element.
 
 For example,
 Given [3,2,1,5,6,4] and k = 2, return 5.
 
 Note:
 You may assume k is always valid, 1 ≤ k ≤ array's length.
 
 Credits:
 Special thanks to @mithmatt for adding this problem and creating all test cases.
 
 Hide Company Tags Facebook Amazon Microsoft Apple Bloomberg Pocket Gems
 Hide Tags Heap Divide and Conquer
 Hide Similar Problems (M) Wiggle Sort II (M) Top K Frequent Elements (E) Third Maximum Number
*/

public class Solution {
    
    // using nth_element function.  Incomplete sort. (9ms runtime).
    int findKthLargest(vector<int>& nums, int k) {
        
        int size = nums.size();
        if (size == 0 || k > size) return -1;
        nth_element(nums.begin(), nums.end() - k, nums.end());
        return nums[size-k];
    }
    
    // Quick select algorithm JAVA (3 ms)
    // O(n) average case.  O(n^2) worse case if poor randomization.
    // O(1) space.  Inplace solution.
    public int findKthLargest(int[] arr, int k)
    {
        int left = 0, right = arr.length - 1, target = arr.length - k;
        Random random = new Random();
        while(left <= right) {
            int index = partition(arr, left, right, random.nextInt(right - left + 1) + left);
            if(index == target) return arr[index]; // found
            if(index > target) right = index - 1;
            else left = index + 1;
        }
        return -1; // k is not valid
    }
    
    /*
     *  function partition(list, left, right, pivotIndex)
     pivotValue := list[pivotIndex]
     swap list[pivotIndex] and list[right]  // Move pivot to end
     storeIndex := left
     for i from left to right-1
     if list[i] < pivotValue
     swap list[storeIndex] and list[i]
     increment storeIndex
     swap list[right] and list[storeIndex]  // Move pivot to its final place
     return storeIndex
     */
    private static int partition(int[] arr, int start, int end, int pivot)
    {
        int pivotValue = arr[pivot];
        swap(arr, pivot, end);
        int storeIndex = start;
        for (int i=start; i<end; ++i)
        {
            if (arr[i] < pivotValue)
            {
                swap(arr, storeIndex, i);
                storeIndex++;
            }
        }
        swap(arr, end, storeIndex);
        return storeIndex;
        
    }
    
    private static void swap(int[] arr, int i, int j)
    {
        int tmp = arr[i];
        arr[i] = arr[j];
        arr[j] = tmp;
    }
    
}
