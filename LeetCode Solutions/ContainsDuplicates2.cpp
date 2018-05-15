/* Given an array of integers and an integer k, find out whether there there are two distinct indices i and j in the array such that nums[i] = nums[j] and the difference between i and j is at most k.
 */

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        set<int> slide;
        queue<int> lru;
        
        if (nums.size() == 0 || k <= 0)
        {
            return false;
        }
        
        int tail = nums[0];
        
        for(int i=0; i<nums.size(); ++i)
        {
            if (!slide.insert(nums[i]).second)
            {
                // dup exists in k range
                return true;
            }
            
            lru.push(nums[i]);
            
            if (lru.size() > k)
            {
                slide.erase(lru.front());
                lru.pop();
            }
        }
        
        return false;
    }
};