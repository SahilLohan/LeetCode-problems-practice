// Link :- https://leetcode.com/problems/move-zeroes/description/?envType=study-plan&id=algorithm-i


// Code :- 

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int here=0;
        for(auto element: nums)
        {
            if(element!=0)
            {
                nums[here]=element;
                here++;
            }
        }

        while(here<nums.size())
        {
            nums[here]=0;
            here++;
        }
        
    }
};
