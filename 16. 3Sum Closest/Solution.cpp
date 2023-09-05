// Link : https://leetcode.com/problems/3sum-closest/description/


// Code : 
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        
        int start;
        int end;
        int diff=INT_MAX;
        int ans;
        int val;
        sort(nums.begin(),nums.end());

        for(int i=0;i<nums.size()-2;i++)
        {
            start = i+1;
            end = nums.size()-1;

            while(start < end)
            {
                val = nums[i]+nums[start]+nums[end];

                if(val == target)
                {
                    return val;
                }
                else if(val < target)
                {
                    start++;
                }
                else
                {
                    end--;
                }

                if(diff > abs(target - val))
                {
                    diff = abs(target - val);
                    ans = val;
                }
            }
        }

        return ans;
    }
};
