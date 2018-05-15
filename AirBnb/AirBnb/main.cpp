//
//  main.cpp
//  AirBnb
//
//  Created by Isaiah Paradiso on 2/14/17.
//  Copyright © 2017 industries. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

/*
struct op
{
    int accountId;
    int timestamp;
    int amount;  // range sum up to this point
    
    op(int id, int ts, int amt)
    {
        accountId = id;
        timestamp = ts;
        amount = amt;
    }
};


class Banker
{
public:
    
    void credit(int accountId, int timestamp, int amount)
    {
        doOperation(accountId, timestamp, amount);
    }
    
    void debit(int accountId, int timestamp, int amount)
    {
        doOperation(accountId, timestamp, -amount);
    }
    
    int balance(int accountId, int start, int end)
    {
        // binary search start time & end time
        auto it = m_transHistory.find(accountId);
        if (it == m_transHistory.end())
        {
            return -1; // throw or whater
        }
        
        auto& list = it->second;
        
        // check ranges first
        int left = binarySearch(list, 0, list.size()-1, start);
        
        int right = binarySearch(list, left, list.size()-1, end);
        
        // return list[end].amount - list[start].amount;
        return list[right].amount - list[left].amount;
    }
    
protected:
    
    
    int binarySearch(vector<op>& history, size_t left, size_t right, int targetTime)
    {
        if (left >= right)
        {
            return left;
        }
        
        int mid = left + (right - left) / 2;
        
        if (history[mid].timestamp == targetTime)
        {
            return mid;
        }
        else if (history[mid].timestamp > targetTime)
        {
            // go left
            return binarySearch(history, left, mid, targetTime);
        }
        else
        {
            // go right
            return binarySearch(history, mid+1, right, targetTime);
        }
    }
    
    
    void doOperation(int accountId, int timestamp, int amount)
    {
        // get the transHistory
        auto& list = m_transHistory[accountId];
        
        if (list.size() == 0)
        {
            // push a dummy head
            list.push_back({0, 0, 0});
        }
        
        op trans(accountId, timestamp, amount);
        
        if (list.size() > 0)
        {
            trans.amount += list.back().amount;
        }
        
        list.push_back(trans);
    }
    
    unordered_map<int, vector<op>> m_transHistory;
};





int main(int argc, const char * argv[]) {
    // insert code here...

    
    Banker bank;
    

    
    bank.credit(1, 2, 4);
    bank.credit(1, 4, 3);
    bank.debit(1, 5, 4);
    bank.credit(1, 8, 1);
    bank.debit(1, 10, 2);
    
    cout << bank.balance(1, 3, 9) << endl;
    
    
    
    return 0;
}


*/




struct routeLeg
{
    string start;
    string end;
    int cost;
};

struct IdealRoute
{
    vector<routeLeg> route;
    int cost;
};



class IdealRouter
{
    
public:
    
    IdealRoute findIdealRoute(vector<routeLeg>& legs, int k, string start, string destination)
    {
        unordered_map<pair<int, int>, int> memo;
        
        vector<routeLeg> current;
        
        IdealRoute result;
        
        for (int i=0; i<legs.size(); i++)
        {
            if (legs[i].start.equals(start))
            {
                backtrack(legs, i, 0, k, current, result, memo);
            }
        }
        
        
        return result;
        
    }
    
    // record results for start position, size of route -> memoize result
    
protected:
    
    void tryUpdateResult(int cost, vector<routeLeg>& current, IdealRoute& result)
    {
        if(results.cost < cost)
        {
            result.cost = cost;
            result.route = current;
        }
    }
    
    void backtrack(vector<routeLeg>& legs,
                   int start,
                   int currentSum,
                   int k,
                   vector<routeLeg>& current,
                   IdealRoute& result,
                   unordered_map<pair<int, int>, int>& memo,
                   string& destination)
    {
        if (start >= lengs.length() || current.size() > k)
        {
            return;
        }
        
        pair<int, int> key = make_pair(start, currentSum);
        auto iter = memo.find(key);
        if (iter != memo.end() )
        {
            // if we're at the destination node
            if (legs[start].end == destination)
            {
                tryUpdateResult(currentSum, current);
                return;
            }
            return;
        }
        
        // if we're at the destination node
        if (legs[start].end == destination)
        {
            tryUpdateResult(currentSum, current);
            return;
        }
        
        for (int i = start; i < legs.size(); ++i)
        {
            
            // choose current route or not
            current.push_back(legs[i]);
            backtrack(legs, i+1, currentSum + legs[i].cost, k, current, result, memo, destination);
            current.pop_back();
            backtrack(legs, i+1, currentSum, k, current, result, memo, destination);
            
            // memoize result to reduce recursion
            memo[key] = currentSum;
        }
        
        
        
    }
    
};










int main(int argc, const char * argv[]) {
    // insert code here...

    IdealRouter ir;
    
    return 0;
}

