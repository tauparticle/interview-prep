/*
 Reverse bits of a given 32 bits unsigned integer.
 
 For example, given input 43261596 (represented in binary as 00000010100101000001111010011100), return 964176192 (represented in binary as 00111001011110000010100101000000).
 
 Follow up:
 If this function is called many times, how would you optimize it?
 
 */



class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        
        int lower = 0;
        int higher = 31;
        
        while (lower < higher) {
            bool lb = getBit(n, lower);
            bool ub = getBit(n, higher);
            if (lb != ub)
            {
                if (ub && !lb) {
                    n = setBit(n, lower);
                    n = clearBit(n, higher);
                }
                else if (!ub && lb) {
                    n = setBit(n, higher);
                    n = clearBit(n, lower);
                }
            }
            
            lower++;
            higher--;
        }
        
        return n;
    }
    
    bool getBit(uint32_t num, int i) {
        return ((num & (1 << i)) != 0);
    }
    
    uint32_t clearBit(uint32_t num, int i) {
        int mask = ~(1 << i);
        return num & mask;
    }
    
    uint32_t setBit(uint32_t num, int i) {
        return num | (1 << i);
    }
};