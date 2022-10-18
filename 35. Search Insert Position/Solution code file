// Link for problem :- https://leetcode.com/problems/search-insert-position/description/


// code --->


class Solution {
public:
    int search(vector<int>& nums, int target,int low,int high)
    {
        if(low>=high)
        {
            if(target>nums[low])
            return low+1;
            else return low;
        }
        else
        {
            int mid=(low+high)/2;
            if(nums[mid]==target)
            {
                return mid;
            }
            else if(nums[mid]<target)
            {
                low=mid+1;
                
                return search(nums,target,low,high);
            }
            else{
                high=mid-1;
                
                return search(nums,target,low,high);
            }
        }
    }

    int searchInsert(vector<int>& nums, int target) {
        return search(nums,target,0,nums.size()-1);


    }
};
