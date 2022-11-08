// Link :- https://leetcode.com/problems/make-the-string-great/description/

// code --->


class Solution {
public:

    string makeGood(string s) {
        string ans;
        stack<char> stk;


        for(int i=0;i<s.length();i++)
        {
            if(stk.empty())
            {
                stk.push(s[i]);
            }
            else
            {
                if(abs(stk.top()-s[i])!=32)
                {
                    stk.push(s[i]);
                }
                else{
                    stk.pop();
                }
            }
        }

        while(!stk.empty())
        {
            ans.push_back(stk.top());
            stk.pop();
        }
        reverse(ans.begin(),ans.end());

        return ans;

    }
};
