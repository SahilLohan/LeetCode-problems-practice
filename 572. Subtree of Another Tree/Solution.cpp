// Link :https://leetcode.com/problems/subtree-of-another-tree/


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
    bool sameTree(TreeNode* x,TreeNode* y)
    {
        if(!x && !y) 
            return true;

        if((!x&&y)||(x&&!y))    
            return false;
        
        return (x->val == y->val && sameTree(x->left,y->left) && sameTree(x->right,y->right));
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        queue<TreeNode*> q;

        TreeNode* cur;
        q.push(root);
        int limit;

        while(!q.empty())
        {
            limit = q.size();
            while(limit--)
            {
                cur = q.front();
                q.pop();

                if(sameTree(cur,subRoot)) return true;

                if(cur->left) q.push(cur->left);
                if(cur->right) q.push(cur->right);
            }
        }

        return false;
    }
};
