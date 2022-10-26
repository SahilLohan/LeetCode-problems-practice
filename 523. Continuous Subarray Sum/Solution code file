// Link :- https://leetcode.com/problems/continuous-subarray-sum/description/


// code --->


class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int sum=0;
        int pre=0;
        for(int i=0;i<nums.size();i++)
        {
            sum += nums[i];
            if(sum%k==0 && i!=0) return true;
            if(mp[sum%k]==0)
            {
                mp[sum%k]=i+1;
            }
            else if(mp[sum%k]<i)
            return true;

        }
        return false;
    }
};
