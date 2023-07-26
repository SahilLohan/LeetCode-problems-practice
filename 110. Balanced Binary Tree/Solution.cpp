// Link : https://leetcode.com/problems/balanced-binary-tree/


// Code :
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
    int maxDepth(TreeNode* root)
    {
        if(!root) return 0;

        int l = maxDepth(root->left);
        int h = maxDepth(root->right);
        return max(l,h)+1;
    }

    bool isBalanced(TreeNode* root) {
        if(!root) return true;

        int ans=abs(maxDepth(root->left) - maxDepth(root->right));
        bool leftAns=isBalanced(root->left);
        bool rigthAns= isBalanced(root->right);
        if(ans<=1 && leftAns && rigthAns)
        {
            return true;
        }
        else return false;
    }
};
