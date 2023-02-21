// Link :- https://leetcode.com/problems/binary-search/description/?envType=study-plan&id=algorithm-i


// Code :-

class Solution {
public:
    

    int search(vector<int>& nums, int target) {
        int l=0;
        int h=nums.size()-1;

        int mid=0;

        while(l<=h)
        {
            // cout << "l: "<<l<<" h: "<<h<< endl;
            mid=(l+h)/2;
            if(nums[mid]==target)
                return mid;
            else if(nums[mid]<target)
                l=mid+1;
            else
                h=mid-1;
            
            // cout << " nums[mid]: "<< nums[mid] << endl;
            
        }

        return -1;
    }
};
