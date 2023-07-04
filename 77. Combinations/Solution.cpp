// Link :https://leetcode.com/problems/combinations/

// Code : 

class Solution {
public:
    vector<vector<int>> ans;
    vector<int> temp;
    int limit=0;
    int k=0;

    void solve(int num)
    {
        if(num==limit || temp.size()==k)
        {
            if(temp.size()==k)
                ans.push_back(temp);
            
            return;
        }
        else
        {
            temp.push_back(num);
            if(temp.size()<=k)
            {
                solve(num+1);
            }
            temp.pop_back();
            solve(num+1);
        }
    }

    vector<vector<int>> combine(int n, int k) {
        this->limit=n+1;
        this->k = k;
        int num=1;
        solve(num);

        return ans;
    }
};
