// Link : https://leetcode.com/problems/validate-binary-search-tree/


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
    vector<int> ans;

    void solve(TreeNode* root)
    {
        if(!root) return;

        solve(root->left);
        ans.push_back(root->val);
        solve(root->right);
    }
    bool isValidBST(TreeNode* root) {
        solve(root);
        for(int i=0;i<ans.size()-1;i++)
        {
            if(ans[i] >= ans[i+1])
            return false;
        }
        return true;
    }
};
