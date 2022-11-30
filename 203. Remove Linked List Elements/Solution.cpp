// Link :- https://leetcode.com/problems/remove-linked-list-elements/description/


// code :- 


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
    int val;
    ListNode* temp;
    int count=0;
    void deleteAndMoveAhead(ListNode* node)
    {
        count++;
        if(node==nullptr)
        {
            return;
        }
        else if(node->next == nullptr)
        {
            return;
        }
        else
        {
            if(node->next->val == val)
            {
                temp=node->next;
                node->next=temp->next;
                delete temp;
                deleteAndMoveAhead(node);
            }
            else
            {
                deleteAndMoveAhead(node->next);
            }
            
        }
    }

    ListNode* removeElements(ListNode* head, int val) {
        this->val=val;
        if(head!=nullptr)
        {
            deleteAndMoveAhead(head);
            if(head->val==val)
            {
                temp=head;
                head=head->next;
                delete temp;
            }
        }
        
        cout << count;
        return head;
    }
};
