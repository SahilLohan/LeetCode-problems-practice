// Link : https://leetcode.com/problems/counting-bits/


// Code :

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> bitsIn(n+1);
        bitsIn[0] = 0;
        int num,count;
        for(int i=1;i<n+1;i++)
        {   
            count=0;
            num = i;
            while(num!=0)
            {
                num = num & (num-1);
                count++;
            }
            bitsIn[i] = count;
        }

        return bitsIn;
    }
};
