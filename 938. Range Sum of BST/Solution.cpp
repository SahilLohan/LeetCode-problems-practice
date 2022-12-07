// Link :- https://leetcode.com/problems/range-sum-of-bst/description/

// code :-

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
    int sum=0;
    int l,h;
    void inorder(TreeNode* root)
    {
        if(root==nullptr) return;

        inorder(root->left);
        if(root->val <= h && root->val >= l)
        {
            sum=sum+root->val;
        }
        inorder(root->right);
    }
    int rangeSumBST(TreeNode* root, int low, int high) {
        l=low;
        h=high;
        inorder(root);
        return sum;
    }
        
};
