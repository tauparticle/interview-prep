//
//  Median_Two_Sorted_Arrays.h
//  Interview_Prep_Native
//
//  Created by Isaiah Paradiso on 5/28/16.
//  Copyright © 2016 poot industries. All rights reserved.
//

#ifndef Median_Two_Sorted_Arrays_h
#define Median_Two_Sorted_Arrays_h


#endif /* Median_Two_Sorted_Arrays_h */
#include <vector>

class MedianSortedArrays {
public:
    
    // computes median by counting by 1/2 until we reach the median value
    double findMedianSortedArrays_divideAndConquer(std::vector<int>& nums1, std::vector<int>& nums2)
    {
        
        int m = (int)nums1.size();
        int n = (int)nums2.size();
        int total = m+n;
        if(total%2 == 1)
        {
            return helper(nums1, m, nums2, n, total/2+1, 0, 0);
        }
        else
        {
            double a = helper(nums1, m, nums2, n, total/2, 0, 0);
            double b = helper(nums1, m, nums2, n, total/2+1, 0, 0);
            return (a + b) / 2;
        }
        
    }
    
    // counts by 1/2.  Logic is simplified by enforcing smaller array first
    double helper(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n, int k, int start1, int start2)
    {
        if(m > n)
        {
            return helper(nums2, n, nums1, m, k, start2, start1);
        }
        
        if(m == 0)
        {
            return nums2[k-1];
        }
        if(k == 1)
        {
            return std::min(nums1[start1], nums2[start2]);
        }
        int a = std::min(k/2, m);
        int b = k-a;
        if(nums1[a+start1-1] <= nums2[b+start2-1])
        {
            return helper(nums1, m-a, nums2, n, k-a, start1+a, start2);
        }
        else
        {
            return helper(nums1, m, nums2, n-b, k-b, start1, start2+b);
        }
    }
    
    // computes median by counting up to median value and returning that O(n/2)
    double findMedianSortedArrays_counting(std::vector<int>& nums1, std::vector<int>& nums2)
    {
        size_t size = nums1.size() + nums2.size();
        int end;
        bool even = size % 2 == 0;
        int a = 0;
        int b = 0;
        int i = 0;
        int num = 0;
        
        if (size == 0) return 0;
        if (size == 1) return nums1.size() > 0 ? nums1[0] : nums2[0];
        while (i < size/2)
        {
            if (a < nums1.size() && b < nums2.size())
            {
                if (nums1[a] < nums2[b])
                {
                    num = nums1[a];
                    a++;
                }
                else
                {
                    num = nums2[b];
                    b++;
                }
            }
            else if (a < nums1.size())
            {
                // b is at the end, just keep iterating with a
                num = nums1[a];
                a++;
            }
            else
            {
                // a is at the end, just keep iterating with b
                num = nums2[b];
                b++;
            }
            
            i++;
        }
        
        if (!even)
        {
            return num;
        }
        else
        {
            int next = 0;
            if (a < nums1.size() && b < nums2.size())
            {
                if (nums1[a] < nums2[b])
                {
                    next = nums1[a];
                }
                else
                {
                    next = nums2[b];
                }
            }
            else if (a < nums1.size())
            {
                // b is at the end, just keep iterating with a
                next = nums1[a];
            }
            else
            {
                // a is at the end, just keep iterating with b
                next = nums2[b];
            }
            
            return (num + next) / 2.0;
        }
        
    }
};