// Link :- https://leetcode.com/problems/find-pivot-index/description/?envType=study-plan&id=level-1

// Code :- 

class Solution {
public:
    int pivotIndex(vector<int>& n) {
        vector<int> nums=n;

        for(int i=1;i<nums.size();i++)
        nums[i]+=nums[i-1];

        int leftSum=0;
        int rightSum=0;

        for(int i=0;i<n.size();i++)
        {
            i==0?leftSum=0:leftSum=nums[i-1];
            i==n.size()-1?rightSum=0:rightSum=nums[nums.size()-1]-nums[i];

            cout << " i , leftsum , rightsum : " << i << " "<< leftSum  << " " << rightSum << endl;
            if(leftSum==rightSum) return i;
        }

        return -1;
    }
};
