// Link :- https://leetcode.com/problems/running-sum-of-1d-array/description/?envType=study-plan&id=level-1

// Code :- 

class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        for(int i=1;i<nums.size();i++)
        nums[i]+=nums[i-1];
        return nums;
    }
};
