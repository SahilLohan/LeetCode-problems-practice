// Link : https://leetcode.com/problems/ransom-note/


// Code : 
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int> mp;

        for(auto ch : ransomNote)
        {
            mp[ch]++;
        }

        for(auto ch : magazine)
        {
            if(mp.find(ch)!=mp.end() && mp[ch]!=0)
            mp[ch]--;
        }

        for(auto e:mp)
        {
            if(e.second!=0)
            return false;
        }

        return true;
    }
};
