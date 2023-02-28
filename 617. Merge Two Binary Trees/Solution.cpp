// Link :- https://leetcode.com/problems/merge-two-binary-trees/description/?envType=study-plan&id=algorithm-i


// Code :- 

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
private:

    void solve(TreeNode* root, TreeNode* root1, TreeNode* root2){
        if(root1!=nullptr && root2!=nullptr)
        {
            root->val = root1->val + root2->val;

            if(root1->left != nullptr && root2->left == nullptr)
            {
                root2->left = new TreeNode(0);
            }
            if(root1->left == nullptr && root2->left != nullptr)
            {
                root1->left = new TreeNode(0);
            }
            if(root1->left!=nullptr && root2->left!=nullptr)
            {
                root->left = new TreeNode(0);
                solve(root->left,root1->left,root2->left);
            }

            if(root1->right != nullptr && root2->right == nullptr)
            {
                root2->right = new TreeNode(0);
            }
            if(root1->right == nullptr && root2->right != nullptr)
            {
                root1->right = new TreeNode(0);
            }
            if(root1->right!=nullptr && root2->right!=nullptr)
            {
                root->right = new TreeNode(0);
                solve(root->right,root1->right,root2->right);
            }
        }

        if(root1!=nullptr && root2==nullptr)
        {
            root=root1;
        }
        if(root1==nullptr && root2!=nullptr)
        {
            root=root2;
        }
    }

public:

    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {

        if(root1!=nullptr && root2==nullptr)
        {
            return root1;
        }
        if(root1==nullptr && root2!=nullptr)
        {
            return root2;
        }
        if(root1==nullptr && root2==nullptr)
        {
            return root2;
        }
        

        TreeNode* root=new TreeNode(0);

        solve(root,root1,root2);

        return root;
    }
};
