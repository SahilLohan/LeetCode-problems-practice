// Link :- https://leetcode.com/problems/squares-of-a-sorted-array/description/?envType=study-plan&id=algorithm-i


// Code :- 

class Solution {
public:
    vector<int> sortedSquares(vector<int> nums) {
        vector<int> arr;

        int left=0,right=nums.size()-1;

        while(nums[left]<0 && left<=right)
        {
            if(left>=nums.size() || right < 0)
            {
                break;
            }
            if(pow(nums[left],2) >= pow(nums[right],2))
            {
                arr.push_back(pow(nums[left],2));
                left++;
            }
            else
            {
                arr.push_back(pow(nums[right],2));
                right--;
            }
            if(left>=nums.size() || right < 0)
            {
                break;
            }
           
        }

        while(right>=left)
        {
            arr.push_back(pow(nums[right],2));
            right--;
        }

        for(int i=0;i<nums.size();i++)
        {
            nums[i]=arr[nums.size()-i-1];
        }

        return nums;
    }
};
