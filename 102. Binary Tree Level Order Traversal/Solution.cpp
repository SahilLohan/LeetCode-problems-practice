// Link : https://leetcode.com/problems/binary-tree-level-order-traversal/



// code : 

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
    vector<vector<int>> levelOrder(TreeNode* root) {
        
        queue<TreeNode*> q;

        vector<vector<int>> ans;
        vector<int> temp;

        if(root!=nullptr)
        q.push(root);
        int n;
        while(!q.empty())
        {
            temp.clear();
            n = q.size();
            for(int i=0;i<n;i++)
            {
                root = q.front();
                q.pop();
                temp.push_back(root->val);
                if(root->left!=nullptr) q.push(root->left);
                if(root->right!=nullptr) q.push(root->right);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};
