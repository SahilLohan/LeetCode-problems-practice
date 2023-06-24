// Link : https://leetcode.com/problems/missing-number/description/

// Code : 
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        // unordered_map<int,int> mp;
        // for(auto num : nums)
        // {
        //     mp[num]++;
        // }

        // for(int i=0;i<=nums.size();i++)
        // {
        //     if(mp[i]==0) return i;
        // }

        // return -1;
        int x=0;
        for(auto num : nums)
        {
            x = x ^ num;
        }
        for(int i=0;i<=nums.size();i++)
        {
            x = x ^ i;
        }

        // x ^ x is always 0

        return x;
    }
};
