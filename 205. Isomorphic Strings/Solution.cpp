// Link :- https://leetcode.com/problems/isomorphic-strings/description/?envType=study-plan&id=level-1

// Code :- class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char,char> mp1;
        map<char,char> mp2;


        for(int i=0;i<s.length();i++)
        {
            
            if(int(mp1[s[i]])==0 && int(mp2[t[i]]==0))
            {
                mp1[s[i]]=t[i];
                mp2[t[i]]=s[i];
            }
            if(mp1[s[i]]!=t[i] || mp2[t[i]]!=s[i])
            return false;
        }

        return true;
    }
};
