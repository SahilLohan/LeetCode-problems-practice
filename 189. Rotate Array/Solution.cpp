// Link :- https://leetcode.com/problems/rotate-array/description/?envType=study-plan&id=algorithm-i


// Code :- 

class Solution {

private:
    void reverse(vector<int>& nums, int l, int r) 
    {
        while (l < r)
        swap(nums[l++], nums[r--]);
    }


public:
    void rotate(vector<int>& nums, int k) {
        k %= nums.size();
        reverse(nums, 0, nums.size() - 1);
        reverse(nums, 0, k - 1);
        reverse(nums, k, nums.size() - 1);
    }
};
