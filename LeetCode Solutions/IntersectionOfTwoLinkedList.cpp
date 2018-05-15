/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/

/* Write a program to find the node at which the intersection of two singly linked lists begins.
If the two linked lists have no intersection at all, return null.
The linked lists must retain their original structure after the function returns.
You may assume there are no cycles anywhere in the entire linked structure.
Your code should preferably run in O(n) time and use only O(1) memory. */
class Solution {
public:
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
	{
		// easy solution is to use a set<ListNode*> and traverse both until a duplicate is intersed into the set.  But that is O(n) space.  
		// this solution finds the depth of the linked list and advances the points to a common length before traversing for a match.  
		// same solution can be used to find lowest common ancestor in a tree.
		ListNode* a = headA;
		ListNode* b = headB;
		int lengthA = getLength(headA);
		int lengthB = getLength(headB);

		while (lengthA > lengthB) {
			a = a->next;
			lengthA--;
		}

		while (lengthB > lengthA) {
			b = b->next;
			lengthB--;
		}

		// advance both pointers forward until they match
		while (a != NULL && b != NULL) {

			if (a == b) {
				return a;
			}

			a = a->next;
			b = b->next;
		}

		return NULL;

	}

private:
	int getLength(ListNode *root)
	{
		int length = 0;
		if (root == NULL) {
			return length;
		}

		while (root != NULL) {
			root = root->next;
			length++;
		}

		return length;
	}
};