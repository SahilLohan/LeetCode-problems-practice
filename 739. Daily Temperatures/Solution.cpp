// Link :- https://leetcode.com/problems/daily-temperatures/


// Code :- 


class Solution {
public:
    int count=0;
    vector<int> dailyTemperatures(vector<int>& nums2) {
        stack<int> s;
        vector<int> ans(nums2.size());
        for(int i=0;i<nums2.size();i++)
        {
            cout <<  i << endl;
            while(!s.empty() && nums2[s.top()]<nums2[i])
            {
                //cout << "For i = " << i <<" -> "<< s.top() << " < " << nums2[i] << "\n";
                ans[s.top()]=i-s.top();
                s.pop();
            }
            s.push(i);
        }

        return ans;
    }
};
