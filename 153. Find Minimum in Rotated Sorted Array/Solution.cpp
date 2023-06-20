// Link : https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/


// Code :- 
class Solution {
public:
    int findMin(vector<int>& nums) {
        int l=0,r=nums.size()-1,m;
        

        while(l < r  &&  nums[l] > nums[r])
        {
            m = (l+r)/2;
            if(l==m)
            {
                l++;
                continue;
            }
            if(nums[l] < nums[m] && nums[r] < nums[m])
            {
                l=m;
            }// note that there will be no number between nums[l] and nums[r]
            else
            {
                r=m;
            }

            if(l>0 && r<nums.size()-1 && nums[l] <= nums[r])
            return nums[0];
        }

        if(l<=nums.size()-1)
            return nums[l];
        if(r>=0)
            return nums[r];

        return -1;
    }
};
