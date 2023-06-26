// Link : https://leetcode.com/problems/merge-intervals/


// Code : 

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        sort(intervals.begin(),intervals.end(),[](vector<int> a , vector<int> b){
            return a[0] < b[0];
        });
        for( auto interval : intervals)
        {
            // cout << interval[0] << " " << interval[1] << endl;
 
            if(ans.size() > 0 && ans[ans.size()-1][1] >= interval[0] && ans[ans.size()-1][0] <= interval[0] )
            {
                if(ans[ans.size()-1][1] < interval[1])
                ans[ans.size()-1][1] = interval[1];
            }
            else
            {
                ans.push_back(interval);
            }
        }
        return ans;
        
    }
};
