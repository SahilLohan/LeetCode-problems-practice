// Link :- https://leetcode.com/problems/find-the-highest-altitude

// code :-

class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int max=0;
        int sum=0;
        for(auto value:gain)
        {
            sum=sum+value;
            if(sum>max)
            {
                max=sum;
            }
        }
        return max;
    }
};
