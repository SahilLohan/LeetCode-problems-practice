// link : https://leetcode.com/problems/minimum-depth-of-binary-tree/


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
    int ans=INT_MAX;

    void solve(TreeNode* root,int height)
    {
        if(!root->left && !root->right)
        {
            if(height<ans)
            ans = height;

            return;
        }
        else
        {
            if(root->left) solve(root->left,height+1);

            if(root->right) solve(root->right,height+1);
        }
    }
    int minDepth(TreeNode* root) {
        if(!root) return 0;
        else
        solve(root,1);

        return ans;    
    }
};
