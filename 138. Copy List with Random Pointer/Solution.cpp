// Link : https://leetcode.com/problems/copy-list-with-random-pointer/


// Code : 
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* ans = nullptr;
        Node* ret = nullptr;
        Node* ptr = head;
        map<Node*,Node*> mp;
        while(ptr)
        {
            if(!ans)
            {
                ans  = new Node(ptr->val);
                ret = ans;
            }
            else
            {
                ans->next = new Node(ptr->val);
                ans = ans->next;
            }
            ptr = ptr->next;
        }

        ptr = head;
        ans = ret;

        while(ans && ptr)
        {
            mp[ptr] = ans;
            ptr = ptr->next;
            ans = ans->next;
        }

        ptr = head;
        ans = ret;

        while(ptr && ans)
        {
            ans->random = mp[ptr->random];
            ptr = ptr->next;
            ans = ans->next;
        }

        return ret;

    }
};
