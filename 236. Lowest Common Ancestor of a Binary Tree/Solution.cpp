// Link : https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/



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
    bool solve(TreeNode* root,TreeNode* x,vector<TreeNode*>& vec)
    {
        if(!root) return false;

        if(root==x)
        {
            vec.push_back(x);
            return true;
        }

        if(solve(root->left,x,vec))
        {
            vec.push_back(root);
            return true;
        }
        else if(solve(root->right,x,vec))
        {
            vec.push_back(root);
            return true;
        }
        return false;

    }


    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> vecP;
        vector<TreeNode*> vecQ;

        bool x = solve(root,p,vecP);
        reverse(vecP.begin(),vecP.end());
        x = solve(root,q,vecQ);
        reverse(vecQ.begin(),vecQ.end());

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
