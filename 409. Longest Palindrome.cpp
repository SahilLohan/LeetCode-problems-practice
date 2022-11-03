// Link :- https://leetcode.com/problems/longest-palindrome/description/


// code --->


class Solution {
public:
    int longestPalindrome(string s) {
        map<char,int> mp;

        for(int i=0;i<s.length();i++)
        {
            ++mp[s[i]];
        }

        int flag=0;
        int count=0;
        for(auto e:mp)
        {
            if(e.second>0 && e.second%2==0)
            {
                count+=e.second;
            }
            else if(e.second>0 && e.second%2!=0)
            {
                if(flag==0)
                {
                    flag=1;
                    count+=e.second;
                }
                else{
                    count+=e.second-1;
                }
            }
        }

        return count;
    }
};
