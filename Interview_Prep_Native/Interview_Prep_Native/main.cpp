//
//  main.cpp
//  Interview_Prep_Native
//
//  Created by Isaiah Paradiso on 5/28/16.
//  Copyright © 2016 poot industries. All rights reserved.
//

#include <iostream>
#include "Reverse_Words_In_String.h"
#include "Reverse_Words_In_StringII.h"
#include "Median_Two_Sorted_Arrays.h"
#include "Longes_Palindrome_String.h"
#include "Remove_Elements_From_Array.h"
#include "Trie.h"
//#include "DikstrasAlgorithm.h"
#include "AlienDictionary.h"
#include "SerializeAndDeserializeTree.h"
#include "Palindrome.h"
#include "HashMap.h"

#include <vector>

int main(int argc, const char * argv[]) {
    // insert code here...
    
    {
        ReverseWords rw;
        std::string words = "   a   b ";
        rw.reverseWords(words);
        std::cout << "words=" << words << std::endl;
    }
    {
        ReverseWords2 rw;
        std::string words = "hi!";
        rw.reverseWords(words);
        std::cout << "words=" << words << std::endl;
    }
    {
        MedianSortedArrays m;
        std::vector<int> a = {1,2,3,4,5,6,7,16,17,18,19,20};
        std::vector<int> b = {8,9,10,11,12,13,14,15};
        std::cout << "median:  " << m.findMedianSortedArrays_divideAndConquer(a, b) << std::endl;
    }
    {
        LongestPalindrome lp;
        std::cout << "abbcde = " << lp.longestPalindrome("abbacde") << std::endl;
        std::cout << "fpracecarlp = " << lp.longestPalindrome("fpracecarlp") << std::endl;
        std::cout << "tsabaf = " << lp.longestPalindrome("tsabaf") << std::endl;
        std::cout << "a = " << lp.longestPalindrome("a") << std::endl;
        std::cout << "aa = " << lp.longestPalindrome("aa") << std::endl;
        std::cout << "aaaaaaa = " << lp.longestPalindrome("aaaaaaa") << std::endl;
    }
    {
        RemoveArray a;
        std::vector<int> v = {3,2,2,3,4,3,3,9,3,1,0,2,6};
        int size = a.removeElement(v, 3);
        a.print(v, size);
        v = {3,3,3};
        size = a.removeElement(v, 3);
        a.print(v, size);

    }
    {
        Trie trie;
        std::vector<std::string> strings = {"a", "apple", "app", "aprocot", "be", "bear"};
        for (auto& s : strings)
        {
            trie.addWord(s);
        }
        
        std::string word = "a";
        std::cout << "word: " << word << ", prefix: " << trie.searchPrefix(word) << ", word: " << trie.searchWord(word) << std::endl;
        word += "p";
        std::cout << "word: " << word << ", prefix: " << trie.searchPrefix(word) << ", word: " << trie.searchWord(word) << std::endl;
        word += "p";
        std::cout << "word: " << word << ", prefix: " << trie.searchPrefix(word) << ", word: " << trie.searchWord(word) << std::endl;
        word += "l";
        std::cout << "word: " << word << ", prefix: " << trie.searchPrefix(word) << ", word: " << trie.searchWord(word) << std::endl;
        word += "e";
        std::cout << "word: " << word << ", prefix: " << trie.searchPrefix(word) << ", word: " << trie.searchWord(word) << std::endl;
        word = "zorro";
        std::cout << "word: " << word << ", prefix: " << trie.searchPrefix(word) << ", word: " << trie.searchWord(word) << std::endl;
        word = "be";
        std::cout << "word: " << word << ", prefix: " << trie.searchPrefix(word) << ", word: " << trie.searchWord(word) << std::endl;
        word = "bea";
        std::cout << "word: " << word << ", prefix: " << trie.searchPrefix(word) << ", word: " << trie.searchWord(word) << std::endl;
        word = "baz";
        std::cout << "word: " << word << ", prefix: " << trie.searchPrefix(word) << ", word: " << trie.searchWord(word) << std::endl;
        
    }
    {
     /*
        GraphVertex* a = new GraphVertex(0);
        GraphVertex* b = new GraphVertex(1);
        GraphVertex* c = new GraphVertex(2);
        GraphVertex* d = new GraphVertex(3);
        GraphVertex* e = new GraphVertex(4);
        Edge a_b(b, 10);
        Edge a_c(c, 11);
        Edge b_d(d, 5);
        Edge c_d(d, 4);
        Edge d_e(e, 10);
        a->edges.push_back(a_b);
        a->edges.push_back(a_c);
        b->edges.push_back(b_d);
        c->edges.push_back(c_d);
        d->edges.push_back(d_e);
        
        vector<GraphVertex*> path = Djikstra::PathSearch(a, e);
     
       */
    }
    {
        TreeNode* root = new TreeNode(5);
        root->left = new TreeNode(2);
        root->left->left = new TreeNode(1);
        root->left->right = new TreeNode(3);
        root->left->right->right = new TreeNode(4);
        root->right = new TreeNode(8);
        root->right->left = new TreeNode(6);
        root->right->left->right = new TreeNode(7);
        root->right->right = new TreeNode(9);
        root->right->right->right = new TreeNode(10);
        
        BinaryTreeSerializer bs;
        std::string s = bs.serialize(root);
        std::cout << "serialized tree = " << s << std::endl;
        
        TreeNode* newRoot = bs.deserialize(s);
        std::cout << newRoot->val << std::endl;
    }
    {
        Palindrome pstuff;
        
        auto shortest = pstuff.shortestPalindrome("abcd");
        cout << "Shortest palindrome for " << "abcd" << " is : " << shortest << endl;
    }
    {
        HashMap map(5);
        
        cout << "put value" << endl;
        cout << map.put(1, "one") << endl;
        cout << map.put(2, "two") << endl;
        cout << map.put(3, "three") << endl;
        cout << map.put(4, "four") << endl;
        cout << map.put(5, "five") << endl;
        cout << map.put(6, "six") << endl;
        cout << map.put(1, "one_prime") << endl;
       
        cout << "get value" << endl;
        cout << map.get(1) << endl;
        cout << map.get(2) << endl;
        cout << map.get(3) << endl;
        cout << map.get(4) << endl;
        cout << map.get(5) << endl;
        cout << map.get(6) << endl;
        
        cout << "key exists" << endl;
        cout << map.containsKey(1) << endl;
        cout << map.containsKey(2) << endl;
        cout << map.containsKey(3) << endl;
        cout << map.containsKey(4) << endl;
        cout << map.containsKey(5) << endl;
        cout << map.containsKey(6) << endl;
        
        cout << "removing & checking" << endl;
        cout << map.remove(1) << endl;
        cout << map.containsKey(1) << endl;
        cout << map.remove(2) << endl;
        cout << map.containsKey(2) << endl;
        cout << map.remove(3) << endl;
        cout << map.containsKey(3) << endl;
        cout << map.remove(4) << endl;
        cout << map.containsKey(4) << endl;
        cout << map.remove(5) << endl;
        cout << map.containsKey(5) << endl;
        cout << map.remove(6) << endl;
        cout << map.containsKey(6) << endl;

        
    }
    
    {
        AlienDictionary dict;
        vector<string> words = {"wrt","wrf","er","ett","rftt"};
        cout << dict.decode(words) << endl;
    }
    
    
    return 0;
}
