// Link : https://leetcode.com/problems/minimum-size-subarray-sum/description/


// Code : 

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int min= INT_MAX;
        vector<int> pSum(nums.size());
        int sum=0;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
            pSum[i]=sum;
        }

        int i=0,j=0;

        while(j<nums.size())
        {
            if(i==0)
            sum = pSum[j];
            else
            sum = pSum[j]-pSum[i-1];

            if(sum >= target)
            {
                if(j-i+1 < min)
                    min=j-i+1;
                
                i++;
            }
            else{
                j++;
            }
        }

        if(min== INT_MAX ) return 0;
        else return min;
    }
};
