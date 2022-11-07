// Link for problem :- https://leetcode.com/problems/maximum-69-number/description/


// code --->


class Solution {
public:
    int maximum69Number (int num) {
        vector<int> number;
        int rem;
        while(num!=0)
        {
            rem=num%10;
            number.push_back(rem);
            num=num/10;
        }
        bool changedAlready=false;
        for(int i=number.size()-1;i>=0;i--)
        {
            if(number[i]==6 && !changedAlready)
            {
                number[i]=9;
                changedAlready=true;
            }
            num=(num*10)+number[i];
        }
        
        return num;
    }
};
