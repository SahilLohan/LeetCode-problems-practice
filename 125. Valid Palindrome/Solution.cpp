// Link :-  https://leetcode.com/problems/valid-palindrome/description/


// Code :- 


class Solution {
public:
    bool isPalindrome(string s) {
        string ans;

        for(int i=0;i<s.length();i++)
        {
            if(isalnum(s[i]))
            {
                if(isupper(s[i]))
                {
                    s[i]=tolower(s[i]);
                }
                ans.push_back(s[i]);
            }
        }

        string temp=ans;
        reverse(temp.begin(),temp.end());
        if(temp==ans)
        return true;

        return false;

    }
};
