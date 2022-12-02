// Link :- https://leetcode.com/problems/assign-cookies/description/


// code :- 


class Solution {
public:
    int findContentChildren(vector<int>& greed, vector<int>& siz) {
        sort(greed.begin(),greed.end(),greater<int>());
        sort(siz.begin(),siz.end(),greater<int>());

        int i=0;
        int j=0;

        int count=0;
        while(i<greed.size() && j < siz.size())
        {
            if(greed[i]<=siz[j])
            {
                i++;
                j++;
                count++;
            }
            else
            {
                i++;
            }
        }
        return count;
    }
};
