// Link : https://leetcode.com/problems/partition-list/


// Code :
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* ans=nullptr;
        ListNode* itr=nullptr;
        ListNode* ptr = head;
        while(ptr)
        {
            if(ptr->val < x)
            {
                if(itr==nullptr)
                {
                    itr = new ListNode(ptr->val);
                    ans = itr;
                }
                else
                {
                    itr->next = new ListNode(ptr->val);
                    itr = itr->next;
                }
            }
            ptr = ptr->next;
        }

        // now number > x

        ptr = head;

        while(ptr)
        {
            if(ptr->val >= x)
            {
                if(itr==nullptr)
                {
                    itr = new ListNode(ptr->val);
                    ans = itr;
                }
                else
                {
                    itr->next = new ListNode(ptr->val);
                    itr = itr->next;
                }
            }
            ptr = ptr->next;
        }

        return ans;
    }
};
