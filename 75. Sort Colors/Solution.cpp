// link : https://leetcode.com/problems/sort-colors/

// Code :

class Solution {
public:
    void sortColors(vector<int>& nums) {

        int i=0,j=nums.size()-1;
        int n=nums.size();
        int index=0;

        // 0 in left and 2 in right

        while(index <= j)
        {
            while(i<n && nums[i]==0)
            {
                i++;
            }

            while(j>=0 && nums[j]==2)
            {
                j--;
            }

            if(i > n || j < 0 )
                break;

            if(index<i)
            {
                index = i;
            }
            else if(nums[index] == 0)
            {
                swap(nums[i] , nums[index]);
            }
            else if(nums[index] == 2)
            {
                swap(nums[j] , nums[index]);
            }
            else
            {
                index++;
            }
        }
        
    }
};
