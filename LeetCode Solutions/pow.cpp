class Solution {
public:
    double myPow(double x, int n) {
        
        if (n == 0) return 1.0;
        if (n == 1) return x;
        if (x == 1) return 1.0;
        if (x == 0) return 0.0;
        
        if (n < 0)
        {
            // special case.  Negating a min leads to overlow.
            if (n == INT_MIN)
            {
                n = INT_MAX;
                x = 1/x;
                return x * x * pow( x*x, n/2 );
            }
            
            n = -n;
            x = 1/x;
        }
        
        if (n % 2 == 0)
        {
            return myPow(x*x, n/2);
        }
        else
        {
            return x*myPow(x*x, n/2);
        }
        
    }
};