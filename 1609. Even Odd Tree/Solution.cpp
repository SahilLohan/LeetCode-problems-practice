// Link : https://leetcode.com/problems/even-odd-tree/


// Code ;
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
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*> q;
        TreeNode* cur;
        vector<int> temp;
        int level=0;
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

                // check temp
                if(temp.size()==1)
                {
                    if(level%2==0 && temp[0]%2==0)
                    return false;
                    if(level%2!=0 && temp[0]%2!=0)
                    return false;

                }
                for(int i=0;i<temp.size()-1;i++)
                {
                    cout << temp[i] << " and " << temp[i+1] << "  " ;
                    if((level%2==0 && temp[i]>=temp[i+1]) || (level%2!=0 && temp[i]<=temp[i+1]))
                    return false;
                    if( (level%2==0 && (temp[i]%2==0 || temp[i+1]%2==0) ) || (level%2!=0 && (temp[i]%2!=0 || temp[i+1]%2!=0) ) ) return false;
                }
                cout << endl;

                level++;
            }
        }
        return  true;
    }
};
