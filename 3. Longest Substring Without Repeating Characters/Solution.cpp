// Link :- https://leetcode.com/problems/longest-substring-without-repeating-characters/description/?envType=study-plan&id=algorithm-i

// Code :- 

class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        if(s.length()==0) return 0;

        int l=0;
        int r=0;

        int max=1;
        unordered_map<char,int> mp;

        // window size = r-l+1
        // 1. increase size of window 
        // 2. move window to right

        while(r<s.length())
        {
            if(mp[s[r]]==0)
            {
                if(r-l+1 > max) max=r-l+1;

                mp[s[r]]++;
                r++;
            }
            else{
                while(l<r && mp[s[r]]!=0)
                {
                    mp[s[l]]--;
                    l++;
                }
            }
        }

        return max;

    }
};
