// Link for problem :- https://leetcode.com/problems/subarray-sum-equals-k/

// code --->

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size(),sum=0,count=0;
        map<int,int> mp;
        for(int i=0;i<n;i++)
        {
            sum=sum+nums[i];
            if(sum==k)
            {
                //cout << "con 2\n";
                count++;
            }
            
            //cout << i << " sum -> "<< sum<< endl;
            if(mp[sum-k]!=0)
            {
                cout<<"con 1\n";
                count+=mp[sum-k];
            }
            ++mp[sum];
        }
        return count;
    }
};
