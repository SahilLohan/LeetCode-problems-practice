// Link : https://leetcode.com/problems/reorder-list/


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

    ListNode* reverseTheList(ListNode* head)
    {
        if(head== nullptr || head->next == nullptr)
        {
            return head;
        }

        ListNode* prev = nullptr;
        ListNode* nxt = head->next;
        while(head)
        {
            head->next = prev;
            prev = head;
            head = nxt;
            if(head)
            nxt = head->next;
        }

        return prev;
    }

    void reorderList(ListNode* head) {
        if(head->next == nullptr || head->next->next == nullptr) return;


        ListNode *fast=head;
        ListNode *slow=head;

        // lets find its mid
        while(fast)
        {
            fast = fast->next;
            if(fast)
            {
                fast = fast->next;
                slow = slow->next;
            }
        }

        ListNode* mid = slow;
                cout << "mid is : " << mid->val << endl;
        ListNode* list1 = head;
        ListNode* list2 = mid->next;
        mid->next=nullptr;

        // reverse the list2
        list2 = reverseTheList(list2);
        ListNode* temp1 = list2;
        while(temp1)
        {
            cout << temp1->val << " ";
            temp1 = temp1->next;
        }
        ListNode* temp = list1->next;
        while(temp && list2)
        {
            list1->next = list2;
            list2 = list2->next;
            list1 = list1->next;
            list1->next = temp;

            list1 = list1->next;
            temp = temp->next;
        }
    }
};
