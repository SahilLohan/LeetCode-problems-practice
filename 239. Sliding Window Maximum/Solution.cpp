// Link : https://leetcode.com/problems/sliding-window-maximum/description/


// Code :
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int,int>> q; // it will store index and value
        vector<int> ans;
        int i=0;
        int j=i;
        while(j<k)
        {
            q.push(make_pair(nums[j],j));
            j++;
        }
        ans.push_back(q.top().first);
        i++;
        while(j<nums.size())
        {
            q.push(make_pair(nums[j],j));
            while(q.top().second<i)
            {
                q.pop();
            }
            ans.push_back(q.top().first);
            i++;
            j++;
        }

        return ans;
    }
};
