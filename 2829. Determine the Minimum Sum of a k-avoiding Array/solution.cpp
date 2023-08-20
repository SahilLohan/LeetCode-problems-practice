class Solution {
public:
    int minimumSum(int n, int k) {
        unordered_map<int,int> mp;
        int sum = 0;
        for(int num=1,len=0;len < n;num++)
        {
            if(num<k)
            {
                if(mp.find(num)==mp.end())
                {
                    sum += num;
                    len++;
                }
                mp[k-num]++;
            }
            else
            {
                sum += num;
                len++;
            }
        }
        
        return sum;
    }
};
