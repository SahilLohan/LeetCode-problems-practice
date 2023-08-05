// Link : https://leetcode.com/problems/combination-sum/


// Code : 
class Solution {
public:
    vector<vector<int>> ans;
    vector<int> temp;

    void solve(vector<int>& arr,int k,int index,int currSum)
    {
        if(currSum==k)
        {
            ans.push_back(temp);
            return;
        }
        if(index>=arr.size() || currSum > k)
        return;

        // choices
        if(index<arr.size())
        {
            temp.push_back(arr[index]);
            solve(arr,k,index,currSum + arr[index]);
            temp.pop_back();

            solve(arr,k,index+1,currSum);
        }
        // include
        
    }

    vector<vector<int>> combinationSum(vector<int>& arr, int k) {
        solve(arr,k,0,0);
        return ans;
    }
};
