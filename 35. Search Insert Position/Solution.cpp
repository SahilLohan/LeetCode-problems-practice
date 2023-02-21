// Link :- https://leetcode.com/problems/search-insert-position/description/?envType=study-plan&id=algorithm-i


// Code :-

class Solution {
public:

        // By recursion
    // int search(vector<int>& nums, int target,int low,int high)
    // {
    //     if(low>=high)
    //     {
    //         if(target>nums[low])
    //         return low+1;
    //         else return low;
    //     }
    //     else
    //     {
    //         int mid=(low+high)/2;
    //         if(nums[mid]==target)
    //         {
    //             return mid;
    //         }
    //         else if(nums[mid]<target)
    //         {
    //             low=mid+1;
                
    //             return search(nums,target,low,high);
    //         }
    //         else{
    //             high=mid-1;
                
    //             return search(nums,target,low,high);
    //         }
    //     }
    // }

    int searchInsert(vector<int>& nums, int target) {
        // return search(nums,target,0,nums.size()-1);

        int l=0;
        int h=nums.size()-1;

        int mid=0;

        while(l<=h)
        {
            mid = (l+h)/2;

            if(nums[mid]==target)
            return mid;
            else if(nums[mid]>target){
                if(l==h) break;
                h=mid-1;
            }
            else if(nums[mid]<target){
                if(l==h) break;
                l=mid+1;
            }
                
        }

        if(target<nums[l]) return l;
        else return h+1;
    }
};
