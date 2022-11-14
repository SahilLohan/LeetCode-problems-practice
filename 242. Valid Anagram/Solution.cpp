// link :- https://leetcode.com/problems/valid-anagram/description/

// code :- 

class Solution {
public:
    bool isAnagram(string s, string t) {
        map<char,int> mp1;
        map<char,int> mp2;
        for(auto ch:s)
        {
            ++mp1[ch];
        }
        for(auto ch:t)
        {
            ++mp2[ch];
        }
        return mp1==mp2;
    }
};
