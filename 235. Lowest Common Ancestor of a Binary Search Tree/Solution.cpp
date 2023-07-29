// Link : https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/


// Code :
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    void solve(TreeNode* root,TreeNode* x,vector<TreeNode*>& vec)
    {
        if(!root) return;

        vec.push_back(root);

        if(root== x)
        {
            return;
        }
        else if(root->val < x->val)
        {
            solve(root->right,x,vec);
        }
        else
        {
            solve(root->left,x,vec);
        }
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> vecP;
        vector<TreeNode*> vecQ;

        solve(root,p,vecP);
        solve(root,q,vecQ);

        int lenP=vecP.size();
        int lenQ=vecQ.size();

        int len = min(lenP,lenQ);

        for(int i=1;i<len;i++)
        {
            if(vecP[i]!=vecQ[i])
                return vecP[i-1];
        }

        if(lenP < lenQ)
        {
            return vecP[vecP.size()-1];
        }
        else
        {
            return vecQ[vecQ.size()-1];
        }
    }
};
