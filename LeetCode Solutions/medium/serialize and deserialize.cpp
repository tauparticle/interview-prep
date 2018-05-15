/*449. Serialize and Deserialize BST   QuestionEditorial Solution  My Submissions
Total Accepted: 638
Total Submissions: 1544
Difficulty: Medium
Contributors: ben65
Serialization is the process of converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer, or transmitted across a network connection link to be reconstructed later in the same or another computer environment.

Design an algorithm to serialize and deserialize a binary search tree. There is no restriction on how your serialization/deserialization algorithm should work. You just need to ensure that a binary search tree can be serialized to a string and this string can be deserialized to the original tree structure.

The encoded string should be as compact as possible.

Note: Do not use class member/global/static variables to store states. Your serialize and deserialize algorithms should be stateless.

Hide Company Tags Amazon
Hide Tags Tree
Hide Similar Problems (H) Serialize and Deserialize Binary Tree

*/


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        
        if (!root) return "* ";
        return to_string(root->val) + " " + serialize(root->left) + serialize(root->right);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        cout << data << endl;
        istringstream  iss(data);
        return decode(iss);
    }
    
    TreeNode* decode(istringstream & iss)
    {
        string str;
        iss >> str;
        if (str == "*")
        {
            return nullptr;
        }
        TreeNode* node = new TreeNode(stoi(str));
        node->left = decode(iss);
        node->right = decode(iss);
        return node;
        
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));