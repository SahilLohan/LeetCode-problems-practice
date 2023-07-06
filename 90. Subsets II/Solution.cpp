// Link : https://leetcode.com/problems/subsets-ii/


// Code : 

class Solution {
private:
    void backTrack(vector<vector<int>> &ans, vector<int> &nums, vector<int> &curr, int index) {
    ans.push_back(curr);
    for(int i = index; i < nums.size(); i++) {
        if(i != index && nums[i] == nums[i-1]) continue;
        curr.push_back(nums[i]);
        backTrack(ans, nums, curr, i+1);
        curr.pop_back();
    }
}
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> curr;
        backTrack(ans, nums, curr, 0);
        
        return ans;
    }
};
