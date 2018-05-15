//
//  SerializeAndDeserializeTree.h
//  Interview_Prep_Native
//
//  Created by Isaiah Paradiso on 9/15/16.
//  Copyright © 2016 poot industries. All rights reserved.
//

#ifndef SerializeAndDeserializeTree_h
#define SerializeAndDeserializeTree_h

#include <sstream>
#include <string>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
 
class BinaryTreeSerializer {
public:
    
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        ostringstream oss;
        serialize(root, oss);
        return oss.str();
    }
    
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string> vals;
        split(data, ',', vals);
        return deserialize(0, vals);
    }
    
private:
    
    TreeNode* deserialize(int index, vector<string>& values)
    {
        if (index == values.size())
        {
            return nullptr;
        }
        TreeNode* node = convert(values[index]);
        int nextIndex = node == nullptr ? index + 2 : index + 1;
        if (node)
        {
            node->left = nextIndex < values.size() ? deserialize(nextIndex, values) : nullptr;
            node->right = nextIndex+1 < values.size() ? deserialize(nextIndex+1, values) : nullptr;
        }
        return node;
    }
    
    TreeNode* convert(string& value)
    {
        if (value.compare("#") == 0)
        {
            return nullptr;
        }
        TreeNode* node = new TreeNode(stoi(value));
        return node;
    }
    
    void serialize(TreeNode* node, ostringstream& oss)
    {
        if (!node)
        {
            oss << "#,";
            return;
        }
        oss << node->val << ",";
        serialize(node->left, oss);
        serialize(node->right, oss);
    }
    
    void split(const string &s, char delim, vector<string> &elems)
    {
        stringstream ss;
        ss.str(s);
        string item;
        while (getline(ss, item, delim))
        {
            if (item.size() > 0)
            {
                elems.push_back(item);
            }
        }
    }
};
#endif /* SerializeAndDeserializeTree_h */
