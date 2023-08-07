// https://leetcode.com/problems/minimum-seconds-to-equalize-a-circular-array/

class Solution {
public:
    int minimumSeconds(std::vector<int>& nums1) {
        if(set<int>(nums1.begin(),nums1.end()).size()<=1) return 0;
        vector<int> nums = nums1;
        int n = nums.size();
        int min_seconds = INT_MAX;
        unordered_map<int,vector<int>> mp;
        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]].push_back(i);
        }

        vector<int> temp;
        int gap;
        int max_gap;
        int min_of_all_gap=INT_MAX;
        int ans=INT_MAX;
        for(auto e:mp)
        {
            // cout << e.first << endl;
            temp = e.second;

            if(temp.size()==1) max_gap = nums.size()-1;
            else
            {
                max_gap=0;
                // cout << "gaps : ";
                for(int i=1;i<temp.size();i++)
                {
                    gap = temp[i]-temp[i-1]-1;
                    cout << gap << " ";
                    if(gap%2!=0) gap++;
                    max_gap = max(gap,max_gap);

                }
                // one more gap in tis vector
                gap = nums.size()-temp[temp.size()-1] - 1 + temp[0];
                // cout << gap << " ";
                max_gap = max(gap,max_gap);
                
            }
            if(max_gap%2!=0) max_gap++;
            // cout << "\nmax gap for element - "<< e.first << " : " << max_gap<<endl;
            min_of_all_gap = min(min_of_all_gap,max_gap);

        }
        // cout << "min of all gap : " << min_of_all_gap << endl;
        
        return min_of_all_gap/2;
        
    }
};


