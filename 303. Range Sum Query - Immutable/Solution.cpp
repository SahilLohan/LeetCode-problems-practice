// Link :- https://leetcode.com/problems/range-sum-query-immutable/


// code :- 


class NumArray {
public:
    vector<int> vec;
    NumArray(vector<int>& nums) {
        if(!nums.empty())
        {
            vec.push_back(nums[0]);
        }
        for(int i=1;i<nums.size();i++)
        {
            vec.push_back(vec[i-1]+nums[i]);
        }
    }
    
    int sumRange(int left, int right) {
        if(left==0)
        return vec[right];
        
        return vec[right]-vec[left-1];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
