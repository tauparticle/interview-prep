/*
 We're going to make our own Contacts application! The application must perform two types of operations:
 
 add name, where  is a string denoting a contact name. This must store  as a new contact in the application.
 find partial, where  is a string denoting a partial name to search the application for. It must count the number of contacts starting with  and print the count on a new line.
 Given  sequential add and find operations, perform each operation in order.
 
 Input Format
 
 The first line contains a single integer, , denoting the number of operations to perform.
 Each line  of the  subsequent lines contains an operation in one of the two forms defined above.
 
 Constraints
 
 
 
 
 It is guaranteed that  and  contain lowercase English letters only.
 The input doesn't have any duplicate  for the  operation.
 Output Format
 
 For each find partial operation, print the number of contact names starting with  on a new line.
 
 Sample Input
 
 4
 add hack
 add hackerrank
 find hac
 find hak
 Sample Output
 
 2
 0
 */

#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

class TrieNode {
public:
    
    unordered_map<char, TrieNode*> children;
    int childCount;
    
    TrieNode() {
        childCount = 0;
    }
    
    void add(const string& s) {
        add(s, 0);
    }
    
    int findChildCount(const string& s) {
        return findChildCount(s, 0);
    }
    
private:
    
    void add(const string& s, int index) {
        
        
        if (index > s.length()) {
            return;
        }
        childCount++;
        
        if (index == s.length()) {
            return;
        }
        
        char c = s[index];
        TrieNode* child = nullptr;
        if (children.find(c) == children.end()) {
            child = new TrieNode();
            children[c] = child;
        } else {
            child = children[c];
        }
        
        child->add(s, index + 1);
        
    }
    
    int findChildCount(const string& s, int index) {
        
        if (index == s.length()) {
            return childCount;
        }
        
        char c = s[index];
        TrieNode* child = nullptr;
        if (children.find(c) == children.end()) {
            return 0;  // prefix doesn't exist
        } else {
            child = children[c]; // search child
            return child->findChildCount(s, index + 1);
        }
    }
};


int main(){
    int n;
    cin >> n;
    TrieNode* root = new TrieNode();
    for(int a0 = 0; a0 < n; a0++){
        string op;
        string contact;
        cin >> op >> contact;
        
        if (op == "add") {
            root->add(contact);
        }
        else if (op == "find") {
            cout << root->findChildCount(contact) << endl;
        }
    }
    return 0;
}

