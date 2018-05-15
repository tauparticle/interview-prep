//
//  HashMap.h
//  Interview_Prep_Native
//
//  Created by Isaiah Paradiso on 2/9/17.
//  Copyright © 2017 poot industries. All rights reserved.
//

#ifndef HashMap_h
#define HashMap_h

#include <vector>
#include <exception>


class IHashMap
{
public:
    
    virtual bool containsKey(int key) = 0;
    
    virtual bool remove(int key) = 0;
    
    virtual string get(int key) = 0;
    
    // returns the value inserted, or the old value if the key already existed
    virtual string put(int key, string value) = 0;
};



class HashMap : IHashMap
{
public:
    HashMap(int defaultSize)
    {
        m_table.resize(defaultSize, nullptr);
    }
    
    bool containsKey(int key) override
    {
        int hash = getHash(key);
        if (m_table[hash] == nullptr)
        {
            return false;
        }
        
        ListNode* head = m_table[hash];
        while (head != nullptr)
        {
            if (head->key == key)
            {
                return true;
            }
            head = head->next;
        }
        return false;
    }
    
    bool remove(int key) override
    {
        int hash = getHash(key);
        if (m_table[hash] == nullptr)
        {
            return false;
        }
        
        ListNode* prev = nullptr;
        ListNode* head = m_table[hash];
        while (head != nullptr && head->key != key)
        {
            prev = head;
            head = head->next;
        }
        
        if (head == nullptr)
        {
            return false;  // node doesn't exist
        }
        
        ListNode* deleteMe = head;
        if (prev == nullptr)
        {
            // head element is deleted.  Point to next
            m_table[hash] = deleteMe->next;
            delete deleteMe;
        }
        else
        {
            prev->next = deleteMe->next;
            delete deleteMe;
        }
        return true;
    }
    
    string get(int key) override
    {
        int hash = getHash(key);
        
        if (m_table[hash] == nullptr)
        {
            throw std::runtime_error("key doesn't exist");
        }
        
        ListNode* head = m_table[hash];
        while (head != nullptr)
        {
            if (head->key == key)
            {
                return head->value;
            }
            head = head->next;
        }
        
        throw std::runtime_error("key doesn't exist");
        
    }
    
    string put(int key, string value) override
    {
        int hash = getHash(key);
        
        if (m_table[hash] == nullptr)
        {
            ListNode* node = new ListNode(nullptr, key, value);
            m_table[hash] = node;
            return value;
        }
        else
        {
            ListNode* prev = nullptr;
            ListNode* head = m_table[hash];
            while (head != nullptr)
            {
                if (head->key == key)
                {
                    // this key exists already.  Update it.
                    string oldValue = head->value;
                    head->value = value;
                    return oldValue;
                }
                prev = head;
                head = head->next;
            }
            
            // at the end of the list
            prev->next = new ListNode(nullptr, key, value);
            return value;
        }
    }
    
    
    
private:
    
    inline int getHash(int key)
    {
        return key % m_table.size();

    }
    
    inline int computeHash(int key)
    {
        return key ^ 31;
    }
    
    struct ListNode
    {
        ListNode* next;
        int key;
        string value;
        
        ListNode(ListNode* n, int k, string v)
        {
            next = n;
            key = k;
            value = v;
        }
    };
    
    vector<ListNode*> m_table;
};

#endif /* HashMap_h */
