//
//  Remove_Elements_From_Array.h
//  Interview_Prep_Native
//
//  Created by Isaiah Paradiso on 6/3/16.
//  Copyright © 2016 poot industries. All rights reserved.
//

#ifndef Remove_Elements_From_Array_h
#define Remove_Elements_From_Array_h

#include <vector>


#endif /* Remove_Elements_From_Array_h */

class RemoveArray {
public:
    int removeElement(std::vector<int>& nums, int val)
    {
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
    
    void print(std::vector<int>& v, int size)
    {
        for (int i=0; i<size; ++i)
        {
            std::cout << v[i] << ",";
        }
        std::cout << std::endl;
    }
};