/*Given an array of integers and an integer k, find out whether there are two distinct indices i and j in the array 
  such that nums[i] = nums[j] and the difference between i and j is at most k.
 */

// naieve linear search, looking back k elements each time. O(min(k,n))  Space O(1)
public boolean containsNearbyDuplicate(int[] nums, int k) {
    for (int i = 0; i < nums.length; ++i) {
        for (int j = Math.max(i - k, 0); j < i; ++j) {
            if (nums[i] == nums[j]) return true;
        }
    }
    return false;
}
// Time Limit Exceeded.



// Binary Search tree (keep a sliding window of k elements using self-balancing BST)
// O(n log(min(k,n)), space O(min(n,k))
public boolean containsNearbyDuplicate(int[] nums, int k) {
    Set<Integer> set = new TreeSet<>();
    for (int i = 0; i < nums.length; ++i) {
        if (set.contains(nums[i])) return true;
        set.add(nums[i]);
        if (set.size() > k) {
            set.remove(nums[i - k]);
        }
    }
    return false;
}
// Time Limit Exceeded.


// Hash table (best).  Iterate with sliding hash set to find duplicate.
// O(n) time and O(min(n,k) space.
public boolean containsNearbyDuplicate(int[] nums, int k) {
    Set<Integer> set = new HashSet<>();
    for (int i = 0; i < nums.length; ++i) {
        if (set.contains(nums[i])) return true;
        set.add(nums[i]);
        if (set.size() > k) {
            set.remove(nums[i - k]);
        }
    }
    return false;
}

