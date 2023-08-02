// Link : https://leetcode.com/problems/next-permutation/description/


// Code :
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i = nums.size()-1;

        int j=i-1;

        while(j>=0 && nums[j] >= nums[j+1])
        {
            j--;
        }
        if(j<0)
        {
            sort(nums.begin(),nums.end());
            return;
        }
        while(i>j && nums[i] <= nums[j])
        {
            i--;
        }

        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;

        reverse(nums.begin()+j+1,nums.end());
    }
};
