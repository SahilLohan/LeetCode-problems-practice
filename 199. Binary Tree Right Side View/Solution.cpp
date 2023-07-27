// Link : https://leetcode.com/problems/binary-tree-right-side-view/


// Code : /**
/* Definition for a binary tree node.
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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        queue<TreeNode*> q;
        vector<int> temp;

        if(!root) return ans;
        else
        {
            q.push(root);
            int limit;
            TreeNode* cur;
            while(!q.empty())
            {
                temp.clear();
                limit=q.size();
                while(limit--)
                {
                    cur = q.front();
                    temp.push_back(cur->val);
                    q.pop();

                    if(cur->left) q.push(cur->left);
                    if(cur->right) q.push(cur->right);
                }
                ans.push_back(temp[temp.size()-1]);

            }
            return ans;
        }
    }
};
