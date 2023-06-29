// Link : https://leetcode.com/problems/group-anagrams/


// Code :

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        
        for(auto x: strs){
            string word = x;
            sort(word.begin(), word.end());
            mp[word].push_back(x);
        }
        
        vector<vector<string>> ans;
        for(auto x: mp){
            ans.push_back(x.second);
        }
        return ans;
    }
};

/*********************************************************
******************* TIME LIMIT EXCEEDED ******************
*********************************************************/


// class Solution {
// public:

//     bool isAnagram(string a,string b)
//     {
//         unordered_map<char,int> mp1,mp2;

//         for(auto ch:a)
//         mp1[ch]++;

//         for(auto ch:b)
//         mp2[ch]++;

//         if(mp1==mp2) return true;

//         return false;
//     }

//     vector<vector<string>> groupAnagrams(vector<string>& strs) {

//         vector<bool> done(strs.size(),false);
//         int count=0,n=strs.size();

//         vector<vector<string>> ans;
//         vector<string> temp;
//         while(count < n)
//         {
//             temp.clear(); 
//             for(int i=0;i<n;i++)
//             {
//                 if(!done[i])
//                 {
//                     if(temp.size()!=0)
//                     {
//                         if(isAnagram(temp[0],strs[i]))
//                         {
//                             temp.push_back(strs[i]);
//                             done[i]=true;
//                             count++;
//                         }
//                     }
//                     else
//                     {
//                         temp.push_back(strs[i]);
//                         done[i]=true;
//                         count++;
//                     }
//                 }
//             }
//             ans.push_back(temp);
//         }
//         return ans;
//     }
// };
