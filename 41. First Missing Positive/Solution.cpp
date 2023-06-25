// Link : https://leetcode.com/problems/first-missing-positive/


// Code : 


class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_map<int,int> mp;
        int max=0;
        for(auto num : nums)
        {
            if(num>max)
            {
                max=num;
            }
            if(num>0)
            mp[num]++;
        }
        for(int ans=1;ans<max;ans++)
        {
            if(mp.find(ans)== mp.end())
                return ans;
        }
        return max+1;
        
    }
};
