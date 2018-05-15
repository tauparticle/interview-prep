// Count the number of prime numbers less than a non-negative number, n
// http://en.wikipedia.org/wiki/Sieve_of_Eratosthenes

public class Solution 
{
    // Runtime solution of O(n log n) with O(n) space

    public int countPrimes(int n) 
    {
        if(n <= 1)
        {
            return 0;
        }

        final boolean[] primes = eratosthenesSieve(n);
        int count = 0;
        for(boolean prime : primes) 
        {
            if(!prime)
            {
                count++;
            }
        }
        return count;
    }

    private boolean[] eratosthenesSieve(int n) 
    {
        final boolean[] sieve = new boolean[n];
        sieve[0] = true;
        sieve[1] = true;

        int sqrt = (int)Math.sqrt(n);
        for(int num = 2; num <= sqrt; num++) 
        {
            if(!sieve[num]) 
            {
                for(int mul = num * num; mul < n; mul+=num) 
                {
                    sieve[mul] = true;
                }
            }
        }

        return sieve;
    }
}
