// Link : https://leetcode.com/problems/maximum-subarray/

// Code :


class Solution {
public:
    int maxSubArray(vector<int>& nums) {


        // **********************************************
        // ************* Time Limit Exceed **************
        // **********************************************


        // vector<int> p(nums.size());
        // int n = nums.size();

        // p[0]=nums[0];
        // for(int i=1;i<n;i++)
        // {
        //     p[i] = nums[i] + p[i-1];

        // }

        // // now find the subarray using two pointers
        // int max = INT_MIN;
        // int l,h,temp;

        // for(l=0;l<n;l++)
        // {
        //     for(h=l;h<n;h++)
        //     {
        //         if(l==0)
        //         {
        //             temp=p[h];
        //         }
        //         else
        //         {
        //             temp=p[h]-p[l-1];
        //         }
        //         if(temp>max)
        //         {
        //             max=temp;
        //         }
        //     }
        // }

        // return max;

        // **********************************************
        // ************* Using Kadane Algo **************
        // **********************************************

        // Linear Time

        int ans=INT_MIN , currSum=0;

        for(auto num : nums)
        {
            if(currSum<0)
                currSum=0;
            
            currSum += num;

            ans=max(ans,currSum);
        }
        return ans;

    }
};
