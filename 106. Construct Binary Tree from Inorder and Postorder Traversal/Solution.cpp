// Link  :https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/


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
    TreeNode* solve(vector<int>& inorder, vector<int>& postorder,unordered_map<int,int>& mp,int& index,int strt,int end)
    {
        if(strt < end || index < 0)
        {
            return nullptr;
        }

        int element = postorder[index];
        int pos = mp[element];
        index--;
        TreeNode* ans = new TreeNode(element);

        ans->right = solve(inorder,postorder,mp,index,strt,pos+1);
        ans->left = solve(inorder,postorder,mp,index,pos-1,end);
        
        return ans;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int,int> mp;
        for(int i=0;i<inorder.size();i++)
        {
            mp[inorder[i]]=i;
        }

        int index=inorder.size()-1;
        return solve(inorder,postorder,mp,index,inorder.size()-1,0);
    }
};
