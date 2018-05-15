/*
 Given a nested list of integers, implement an iterator to flatten it.
 
 Each element is either an integer, or a list -- whose elements may also be integers or other lists.
 
 Example 1:
 Given the list [[1,1],2,[1,1]],
 
 By calling next repeatedly until hasNext returns false, the order of elements returned by next should be: [1,1,2,1,1].
 
 Example 2:
 Given the list [1,[4,[6]]],
 
 By calling next repeatedly until hasNext returns false, the order of elements returned by next should be: [1,4,6].
 */

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */

/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

// stack based solution.  Worst case O(n) memory for all single element NextedIntegers
class NestedIterator {
    stack<NestedInteger> S;
    int nextElement;
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        if (nestedList.size() == 0) return;
        // push into stack reversely
        for (int i = nestedList.size() - 1; i >= 0; i--) {
            S.push(nestedList[i]);
        }
    }
    
    int next() {
        return nextElement;
    }
    
    bool hasNext() {
        while (!S.empty()) {
            NestedInteger current = S.top(); S.pop();
            // if the top element on the stack is an Integer, it is the next element
            if (current.isInteger()) {
                nextElement = current.getInteger();
                return true;
            }
            // else access current NestedInteger's List, and push it into the stack
            vector<NestedInteger> nextList = current.getList();
            if (nextList.size() == 0) continue; // corner case: empty list
            for (int i = nextList.size() - 1; i >= 0; i--) {
                S.push(nextList[i]);
            }
        }
        return false;
    }
};

/*Depth-first-search solution: Basically the idea is to depth-first-search all elements and push it into a vector, which is much easier to implement.*/

class NestedIterator {
    int curIndex;
    vector<int> allElements;
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        curIndex = 0;
        dfs(nestedList, allElements);
    }
    
    void dfs(const vector<NestedInteger> &nestedList, vector<int> &allElements) {
        for (auto N: nestedList) {
            if (N.isInteger()) {
                allElements.push_back(N.getInteger());
            } else {
                dfs(N.getList(), allElements);
            }
        }
    }
    
    int next() {
        int res = allElements[curIndex];
        curIndex++;
        return res;
    }
    
    bool hasNext() {
        return curIndex < allElements.size();
    }
};