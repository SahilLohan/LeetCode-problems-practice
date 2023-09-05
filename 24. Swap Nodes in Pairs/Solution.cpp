// Link : https://leetcode.com/problems/swap-nodes-in-pairs/description/


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
    ListNode* swapPairs(ListNode* head) {
        ListNode* pre=head;
        ListNode* nxt=head;
        if(head && head->next) head = head->next;
        while(pre && nxt->next)
        {
            nxt = nxt->next;
            pre->next = nxt->next;
            nxt->next = pre;
            nxt = pre->next;
            if(pre->next && pre->next->next)
            {
                pre->next = pre->next->next;
            }
            pre = nxt;
        }

        return head;
    }
};
