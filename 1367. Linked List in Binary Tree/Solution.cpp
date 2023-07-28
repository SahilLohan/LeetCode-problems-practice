// Link : https://leetcode.com/problems/linked-list-in-binary-tree/



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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isPossible(ListNode* head,TreeNode* root)
    {
        if(!head) return true;
        if(!root) return false;
        if(head->val != root->val) return false;

        if(isPossible(head->next,root->left)) return true;
        else return isPossible(head->next,root->right);
    }

    bool isSubPath(ListNode* head, TreeNode* root) {
        if(!head) return true;

        if(!root) return false;

        if(root->val == head->val)
        {
            if(isPossible(head,root))
                return true;
        }

        if(isSubPath(head,root->left)) return true;
        else return isSubPath(head,root->right);
    }
};
