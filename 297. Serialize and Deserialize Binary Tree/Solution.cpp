// Link : https://leetcode.com/problems/serialize-and-deserialize-binary-tree/description/


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
class Codec {
public:
    string ans="";

    void DFS(TreeNode* root)
    {
        if(!root) ans += "n ";
        else
        {
            stringstream ss;
            ss << root->val;
            ans += ss.str() + " ";
            DFS(root->left);
            DFS(root->right);
        }
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        DFS(root);
        // cout << ans << endl;
        return ans;
    }


    TreeNode* solve(vector<int> vec,int& index)
    {
        TreeNode* root=nullptr;
        // cout << index << ": index\n";
        if(index >= vec.size() || vec[index]==2000)
        {
            index++;
            return root;
        }
        else
        {
            root = new TreeNode(vec[index]);
            index++;
            root->left = solve(vec,index);
            root->right = solve(vec,index);
        }
        return root;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<int> vec;
        int val=0;
        bool neg=false;
        for(auto ch:data)
        {
            if(ch==' ')
            {
                if(neg)
                val = - val;

                neg = false;
                vec.push_back(val);
                // cout << "Pushed" << val << endl;
                val=0;
            }
            else if(ch=='n')
            {
                val = 2000;
            }
            else if(ch=='-')
            {
                neg = true;
            }
            else{
                val*=10;
                val+= ch-'0';
            }
        } 
        int index=0;
        return solve(vec,index);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
