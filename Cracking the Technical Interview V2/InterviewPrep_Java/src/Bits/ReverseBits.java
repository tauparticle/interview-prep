package Bits;

public class ReverseBits {
	
	// you need treat n as an unsigned value
    public static int reverseBits(int n) {
        
        int lower = 0;
        int higher = 31; 
        
        while (lower < higher) {
            boolean lb = getBit(n, lower);
            boolean ub = getBit(n, higher);
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
    
    static boolean getBit(int num, int i) {
        return ((num & (1 << i)) != 0);
    }
    
    static int clearBit(int num, int i) {
        int mask = ~(1 << i);
        return num & mask;
    }
    
    static int setBit(int num, int i) {
        return num | (1 << i);
    }

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		System.out.print("Reverse " + 1 + " = " + reverseBits(3));
		

	}

}
