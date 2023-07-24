// Link : https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/


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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        
        queue<TreeNode*> q;
        vector<vector<int>> ans;
        vector<int> temp;

        if(root)
        q.push(root);

        int n = q.size();
        int level = 0;
        while(!q.empty())
        {
            temp.clear();
            n = q.size();
            for(int i=0;i<n;i++)
            {
                root = q.front();
                q.pop();
                temp.push_back(root->val);

                
                if(root->left) q.push(root->left);
                if(root->right) q.push(root->right);
            }

            if(level%2==1) reverse(temp.begin(),temp.end());
            ans.push_back(temp);
            level++;
        }

        return ans;
    }
};
