/*138. Copy List with Random Pointer   QuestionEditorial Solution  My Submissions
Total Accepted: 82887
Total Submissions: 315639
Difficulty: Hard
Contributors: Admin
A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.

Return a deep copy of the list.

Hide Company Tags Amazon Microsoft Bloomberg Uber
Hide Tags Hash Table Linked List
Hide Similar Problems (M) Clone Graph
*/

/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if (!head) return nullptr;
        unordered_map<RandomListNode*, RandomListNode*> mapping;
        
        RandomListNode* current = head;
        while (current)
        {
            mapping[current] = new RandomListNode(current->label);
            current = current->next;
        }
        
        current = head;
        while (current)
        {
            auto copy = mapping[current];
            copy->next = mapping[current->next];
            copy->random = mapping[current->random];
            current = current->next;
        }
        
        return mapping[head];
    }
};