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
    ListNode* rotateRight(ListNode* head, int k) {
        int size=0;
        ListNode* ptr=head;

        while(ptr)
        {
            ptr = ptr->next;
            size++;
        }
        // cout << size;
        if(size==0) return head;
        k = k%size;

        k = size-k;
        if(k==size) return head;
        ptr = head;
        ListNode* temp;
        k--;
        while(k>0)
        {
            ptr = ptr->next;
            k--;
        }
        temp = ptr->next;
        ptr->next = nullptr;
        ptr = temp;
        while(temp->next)
        {
            temp=temp->next;
        }
        if(temp) temp->next= head;

        return ptr;
    }
};
