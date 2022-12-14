//Link for problem :- https://leetcode.com/problems/subarray-sums-divisible-by-k/

//code --->
class Solution {
public:
    int subarraysDivByK(vector<int>& arr, int k) {
        int n = arr.size();
        int* prefixArr = new int[arr.size()];
        prefixArr[0]=arr[0];
        
        for(int i=1;i<n;i++)
        {
            prefixArr[i]=prefixArr[i-1]+arr[i];
        }
        
        int count=0;
        
        // prefix sum approach using two loops
        // for(int i=0;i<n;i++)
        // {
        //     if(prefixArr[i]%k==0)
        //     {
        //         count++;
        //     }
        //     for(int j=i+1;j<n;j++)
        //     {
        //         if((prefixArr[j]-prefixArr[i])%k==0)
        //         {
        //             count++;
        //         }
        //     }
        // }
        
        // if they have same remainder.. then it will be counted
        
        
        map<int,int> m;
        int rem;
        for(int i=0;i<n;i++)
        {
            rem=(prefixArr[i]%k)<0?(prefixArr[i]%k)+k:(prefixArr[i]%k);
            
            
            if(m[rem]!=0)
            {
                count+=m[rem];
            }
            ++m[rem];
            if(rem==0)
            {
                count++;   
            }
        }
        return count;
    }
};
