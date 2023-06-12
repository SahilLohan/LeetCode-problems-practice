// Link : https://leetcode.com/problems/maximum-product-subarray/description/

class Solution {
public:
    // without any zero
    int solve(int i,int j,vector<int>& arr)
    {
        if(i < arr.size() && ( i==j || j-i ==1 ) )
        {
            return arr[i];
        }
        else if(i>=0 && j>i && j < arr.size())
        {
            // count no. of -ve numbers
            int count=0;
            int product_till_first=0;
            int product_till_last =0;
            int curr=1;
            for(int index =i ; index <  j ; index++)
            {
                if(index==i)
                {
                    curr = arr[index];
                }
                else
                {
                    curr *= arr[index];
                }


                if(arr[index] < 0)
                {
                    count++;
                    product_till_last = curr/arr[index];
                    if(product_till_first == 0)
                    {
                        product_till_first = curr;
                    }
                }
            }
            // cout << "curr : " << curr << "\nproduct_till_first : " << product_till_first  << "\nproduct_till_last : " << product_till_last << endl;
            if(count%2==0) // even
            {
                return curr;
            }
            else
            {
                return max(product_till_last , (   curr/product_till_first   ));
            }
        }
        else 
            return INT_MIN;
    }

    // main code
    int maxProduct(vector<int>& nums) {
        if(nums.size()==1)
            return nums[0];
        int i=0,n=nums.size(),ans=0;
        
        for(int j=0;j<n;j++)
        {
            if(nums[j]==0)
            {
                ans=max(ans,solve(i,j,nums));
                i=j+1;
            }
            else if(j==n-1)
            {
                nums.push_back(0);
                ans=max(ans,solve(i,j+1,nums));
            }
        }

        return ans;
    }
};
