// Link : https://leetcode.com/problems/repeated-substring-pattern/


// Code :


class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n=s.length();
        
        if(n==0) 
            return false;

        char last_ch = s[n-1];
        string r = s;
        r = last_ch + r;
        r.pop_back();
        for(int i=0;i<n/2;i++)
        {
            if(s==r)
            {
                cout << "I ran " << i+1 << " times";
                return true;
            }
            else
            {
                last_ch = r[n-1];
                r = last_ch + r;
                r.pop_back();
            }
        }

        return false;
    }
};
