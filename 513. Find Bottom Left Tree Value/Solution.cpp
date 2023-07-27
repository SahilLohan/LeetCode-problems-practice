// Link : https://leetcode.com/problems/find-bottom-left-tree-value/


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
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> q;
        TreeNode* cur;
        vector<int> temp;

        if(!root) return -1;
        else
        {
            q.push(root);
            int limit;

            while(!q.empty())
            {
                temp.clear();
                limit=q.size();
                for(int i=0;i<limit;i++)
                {
                    cur = q.front();
                    temp.push_back(cur->val);
                    q.pop();

                    if(cur->left) q.push(cur->left);
                    if(cur->right) q.push(cur->right);
                }
            }
        }
        return  temp[0];
    }
};
