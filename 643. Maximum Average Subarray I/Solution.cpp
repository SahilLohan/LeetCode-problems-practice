// Link :- https://leetcode.com/problems/maximum-average-subarray-i/description/


// Code :- 


class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double max=INT_MIN;
        double avg=0;
        for(int i=0;i<k;i++)
        {
            avg += nums[i];
        }
        avg = avg/k;
        if(avg>max) max=avg;

        // now move ahead

        for(int i=k;i<nums.size();i++)
        {
            avg = avg + ((double)nums[i]-(double)nums[i-k])/k;
            if(avg>max) max=avg;
        }
        return max;
    }
};
