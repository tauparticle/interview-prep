 /*
  You are climbing a stair case. It takes n steps to reach to the top.
  
  Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
  
  Hide Company Tags Adobe Apple
  Hide Tags Dynamic Programming

  */

class Solution {
private:
    
    unordered_map<int, int> m_memo;
public:
    int climbStairs(int n)
    {
        if (m_memo.find(n) != m_memo.end())
        {
            return m_memo[n];
        }
        
        if (n == 1) return 1;
        if (n == 2) return 2;
        
        
        int count = climbStairs(n-1) + climbStairs(n-2);
        m_memo[n] = count;
        
        return count;
    }
};