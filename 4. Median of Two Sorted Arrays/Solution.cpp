// Link : https://leetcode.com/problems/median-of-two-sorted-arrays/description/


// Code :
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) 
    {
        int n=nums1.size()+nums2.size();
        vector<int> nums(n,0);
        int i=0,j=0,limit=0,k=0;

        if(n%2!=0) //odd
        {
            // cout << "n is odd";
            limit= (n+1)/2;
        }
        else
        {
            // cout << "n is even";
            limit= (n/2)+1;
        }

        while(k<n)
        {
            while(k<n && i<nums1.size() && j<nums2.size())
            {
                if(nums1[i]<nums2[j])
                {
                    nums[k]=nums1[i];
                    i++;
                    k++;
                }
                else
                {
                    nums[k]=nums2[j];
                    j++;
                    k++;
                }
            }

            while(k<n && i>=nums1.size() && j<nums2.size())
            {
                nums[k]=nums2[j];
                j++;
                k++;
            }
            while(k<n && i<nums1.size() && j>=nums2.size())
            {
                nums[k]=nums1[i];
                i++;
                k++;
            }
        }

        double ans=0;
        if(n%2!=0) //odd
        {
            ans = nums[limit-1];
        }
        else
        {
            ans = ((double)nums[limit-1] + (double)nums[limit-2])/2;
        }

        return ans;
    }
};
