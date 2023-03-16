// Link :- https://leetcode.com/problems/sort-array-by-parity-ii/description/


// Code :- 


class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        int i=0,j=1;
        // i for even and j for odd
        while(j<=nums.size()-1 && i <=nums.size()-1)
        {
            if(nums[i]%2==0)
            i+=2;
            else if(nums[j]%2!=0)
            j+=2;
            else
            swap(nums[i],nums[j]);
        }
        return nums;
    }
};
