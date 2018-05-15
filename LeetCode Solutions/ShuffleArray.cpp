/*
 // Init an array with set 1, 2, and 3.
 int[] nums = {1,2,3};
 Solution solution = new Solution(nums);
 
 // Shuffle the array [1,2,3] and return its result. Any permutation of [1,2,3] must equally likely to be returned.
 solution.shuffle();
 
 // Resets the array back to its original configuration [1,2,3].
 solution.reset();
 
 // Returns the random shuffling of array [1,2,3].
 solution.shuffle(); */

class Solution {
public:
    Solution(vector<int> nums) {
        m_original = nums;
        m_deck = nums;
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        m_deck = m_original;
        return m_deck;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        
        for (int i=0; i<m_deck.size(); ++i)
        {
            int idx = rand() % (m_deck.size() - i);
            swap(m_deck[idx+i], m_deck[i]);
        }
        return m_deck;
    }
    
private:
    vector<int> m_original;
    vector<int> m_deck;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * vector<int> param_1 = obj.reset();
 * vector<int> param_2 = obj.shuffle();
 */