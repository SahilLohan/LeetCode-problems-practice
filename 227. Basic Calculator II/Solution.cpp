// Link : https://leetcode.com/problems/basic-calculator-ii/


// Code :
class Solution {
public:
    int calculate(string str) {
        string s="";
        for(auto ch:str)
        {
            if(ch!=' ')
            s+=ch;
        }
        stack<int> st;

        int currNum = 0;
        bool negSign = false;
        for(int i=0;i<s.length();i++)
        { 
            currNum=0;
            if(s[i]=='-')
            {
                negSign = true;
                // st.push(currNum);
            }
            else if(s[i]=='+')
            {
                negSign = false;
                // st.push(currNum);
            }
            else if(s[i]=='*')
            {
                negSign = false;
                i++;
                // st.top() ki value change hoegi
                while(i<s.length() && isdigit(s[i]))
                {
                    currNum *= 10;
                    currNum += s[i] - '0';
                    i++;
                }
                i--;
                st.top() = st.top() * currNum;

            }
            else if(s[i]=='/')
            {
                negSign = false;
                i++;
                // st.top() ki value change hoegi
                while(i<s.length() && isdigit(s[i]))
                {
                    currNum *= 10;
                    currNum += s[i] - '0';
                    i++;
                }
                i--;
                
                st.top() = st.top() / currNum;
            }
            else
            {
                while(i<s.length() && isdigit(s[i]))
                {
                    currNum *= 10;
                    currNum += s[i] - '0';
                    i++;
                }
                
                i--;
                if(negSign)
                currNum = -currNum;

                st.push(currNum);

            }
        }
        currNum=0;
        while(!st.empty())
        {
            currNum += st.top();
            st.pop();
        }

        return currNum;
    }
};
