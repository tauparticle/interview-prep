/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode *sortedListToBST(ListNode *head) {
        int sum = 0;
        for (auto p = head; p; p = p->next)
            sum++;
        return sortedListToBSTHelper(head, 0, sum-1);
    }
    
    // straight BST
    TreeNode* sortedListToBSTHelper(ListNode *& list, int start, int end) {
        if (start > end) return NULL;
        // same as (start+end)/2, avoids overflow
        int mid = start + (end - start) / 2;
        auto *leftChild = sortedListToBSTHelper(list, start, mid-1);
        auto *parent = new TreeNode(list->val);
        parent->left = leftChild;
        list = list->next;
        parent->right = sortedListToBSTHelper(list, mid+1, end);
        return parent;
    }
    
};