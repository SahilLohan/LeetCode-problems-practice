// Lnk :- https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/description/?envType=study-plan&id=algorithm-i

// Code :- 

class Solution {
public:
    vector<int> twoSum(vector<int>& num, int t) {
        int l=0;
        int r=num.size()-1;
        vector<int> ans;
        while(l<r)
        {
            if(num[l]+num[r]==t){
                ans.push_back(l+1);
                ans.push_back(r+1);
                break;
            }
            else if(num[l]+num[r]>t){
                r--;
            }
            else if(num[l]+num[r]<t){
                l++;
            }
        }
        return ans;
    }
};
