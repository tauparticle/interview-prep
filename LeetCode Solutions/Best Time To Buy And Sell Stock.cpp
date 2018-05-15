/*
 Say you have an array for which the ith element is the price of a given stock on day i.
 
 If you were only permitted to complete at most one transaction (ie, buy one and sell one share of the stock), design an algorithm to find the maximum profit.
 */

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int profit = 0;
        int mini = 0;
        
        for (int i=1; i<prices.size(); ++i)
        {
            if (prices[i] < prices[mini])
            {
                mini = i;
            }
            profit = max(profit, prices[i] - prices[mini]);
        }
        
        return profit;
        
    }
};