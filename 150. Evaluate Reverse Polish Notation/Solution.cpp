// Link : https://leetcode.com/problems/evaluate-reverse-polish-notation/


// Code :
class Solution {
public:
    int solve(int a,int b,string token)
    {
        if(token[0] == '+')
        return a+b;
        else if(token[0] == '/')
        return a/b;
        else if(token[0] == '-')
        return a-b;
        else 
        return a*b;
    }

    int stringToNum(string str)
    {
        int ans=0;
        int temp;
        bool negative=false;
        for(auto ch:str)
        {
            if(ch=='-')
            {
                negative = true;
                continue;
            }

            temp = ch - '0';
            ans = ans*10;
            ans += temp;
        }
        if(negative)
        return -ans;
        else
        return ans;
    }

    bool isSign(string str)
    {
        if(str=="+" || str=="/" ||str=="-" ||str=="*" )
        return true;
        else
        return false;
    }

    int evalRPN(vector<string>& tokens) {
        int a;
        int b;

        stack<int> st;

        for(auto token:tokens)
        {
            if(!isSign(token))
            {
                st.push(stringToNum(token));
            }
            else
            {
                b = st.top();
                st.pop();
                a = st.top();
                st.pop();

                st.push(solve(a,b,token));
            }
        }

        return st.top();
    }
};
