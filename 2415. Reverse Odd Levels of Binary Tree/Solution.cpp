// Link : https://leetcode.com/problems/reverse-odd-levels-of-binary-tree/



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
    void swapData(TreeNode* a,TreeNode* b)
    {
        int temp = a->val;
        a->val = b->val;
        b->val = temp;
    }

    TreeNode* reverseOddLevels(TreeNode* r) {
        TreeNode* root = r;
        queue<TreeNode*> q;
        vector<TreeNode*> temp;

        if(root!=nullptr)
        q.push(root);
        int n;
        int level = 0;
        int i,j;
        while(!q.empty())
        {
            temp.clear();
            n = q.size();
            for(int i=0;i<n;i++)
            {
                root = q.front();
                q.pop();
                temp.push_back(root);

                if(root->left!=nullptr) q.push(root->left);
                if(root->right!=nullptr) q.push(root->right);
            }
            
            if(level%2!=0) // odd level
            {
                i=0;
                j=temp.size()-1;
                while(i<j)
                {
                    swapData(temp[i],temp[j]);

                    i++;
                    j--;                    
                }
            }
            level++;
        }


        return r;
    }
};
