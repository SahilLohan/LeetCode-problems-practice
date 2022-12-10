// Link :- https://leetcode.com/problems/merge-similar-items/description/

// code :- 

class Solution {
public:
    vector<vector<int>> mergeSimilarItems(vector<vector<int>>& items1, vector<vector<int>>& items2) 
    {
        unordered_map<int,int> mp;
        vector<int> temp;
        vector<int> pushIt;
        vector<vector<int>> ret;

        for(auto items:items1)
        {
            // items[0] is value
            // items[1] is weight
            mp[items[0]]+=items[1];
        }
        for(auto items:items2)
        {
            // items[0] is value
            // items[1] is weight

            mp[items[0]]+=items[1];
        }
        for(auto e:mp)
        {
            temp.push_back(e.first);
        }
        sort(temp.begin(),temp.end());
        for(int e:temp)
        {
            pushIt.push_back(e);
            pushIt.push_back(mp[e]);
            ret.push_back(pushIt);
            pushIt.clear();
        }

    return ret;
        
    }
};
