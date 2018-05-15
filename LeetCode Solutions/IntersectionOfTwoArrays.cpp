/*
 Given two arrays, write a function to compute their intersection.
 
 Example:
 Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return [2, 2].
 
 Note:
 Each element in the result should appear as many times as it shows in both arrays.
 The result can be in any order.
 Follow up:
 What if the given array is already sorted? How would you optimize your algorithm?
 What if nums1's size is small compared to num2's size? Which algorithm is better?
 What if elements of nums2 are stored on disk, and the memory is limited such that you cannot load all elements into the memory at once?
*/


class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() < nums2.size())
        {
            return doIntersect(nums1, nums2);
        }
        return doIntersect(nums2, nums1);
    }
    
    // runtime O(n log n) due to sorting
    // memory O(1) aside from resulting array;
    // this takes about 8ms on average
    vector<int> twoPointerImpl(vector<int>& a, vector<int>& b)
    {
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        vector<int> result;
        
        int i = 0;
        int j = 0;
        while (i < a.size() && j < b.size())
        {
            if (a[i] == b[j])
            {
                result.push_back(a[i]);
                i++; j++;
            }
            else if (a[i] < b[j])
            {
                i++;
            }
            else
            {
                j++;
            }
        }
        
        return result;
    }
    
    typedef pair<int, int> TCounts;
    typedef map<int, TCounts> ValueCounts;
    // runtime O(n + m)
    // space O(m), where m is the smaller
    //    worst case is O(n) for same size
    // this takes about 16 ms on average
    vector<int> doIntersect(vector<int>& smaller, vector<int>& larger)
    {
        ValueCounts counts;
        vector<int> results;
        
        for (int i : smaller)
        {
            TCounts& c = counts[i];
            c.first++;
        }
        
        for (int j : larger)
        {
            ValueCounts::iterator iter = counts.find(j);
            if (iter != counts.end())
            {
                TCounts& c = iter->second;
                c.second++;
            }
        }
        
        for (ValueCounts::iterator iter = counts.begin(); iter != counts.end(); ++iter)
        {
            int value = iter->first;
            TCounts& c = iter->second;
            int unique = min(c.first, c.second);
            while (unique > 0)
            {
                results.push_back(value);
                unique--;
            }
        }
        
        return results;
        
    }
};