// Link : https://leetcode.com/problems/flatten-binary-tree-to-linked-list/description/


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

    void flatten(TreeNode* root){
        if(!root) return;
        if(!root->left) 
        {
            root = root->right;
            flatten(root);
            return;
        }

        TreeNode* ryt = root->right;

        root->right = root->left;
        root->left = nullptr;

        flatten(root->right);

        while(root->right)
        {
            root = root->right;
        }

        root->right = ryt;

        flatten(root->right);
    }

    // void solve(stack<TreeNode*>& st,TreeNode* root)
    // {
    //     if(!root) return;

    //     st.push(root);
    //     solve(st,root->left);
    //     solve(st,root->right);
    // }

    // void flatten(TreeNode* root) {
    //     stack<TreeNode*> st;
    //     solve(st,root);
    //     TreeNode* temp = nullptr;
    //     while(!st.empty())
    //     {
    //         st.top()->left = nullptr;
    //         st.top()->right = temp;
    //         temp = st.top();
    //         st.pop();
    //     }
    //     root = temp;
    // }
};
