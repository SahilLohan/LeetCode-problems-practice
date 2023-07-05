// Link : https://leetcode.com/problems/permutations/



// Code :
class Solution {
public:
    vector<int> nums;
    unordered_map<int,int> mp;
    vector<vector<int>> ans;

    void solve(vector<int>& temp,int itr)
    {
        if(itr==nums.size())
        {
            if(temp.size()==nums.size())
            ans.push_back(temp);

            return;
        } 
        else
        {
            for(auto num:nums)
            {
                if(mp[num]==0)
                {
                    mp[num]++;
                    temp.push_back(num);
                    solve(temp,itr+1);
                    temp.pop_back();
                    mp[num]--;
                    solve(temp,itr+1);
                }
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        this->nums = nums;
        vector<int> temp;
        solve(temp,0);

        return ans;
    }
};
