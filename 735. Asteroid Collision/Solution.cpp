// Link : https://leetcode.com/problems/asteroid-collision/


// Code : 
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asts) {
        stack<int> st;
        vector<int> ans;
        bool canStop=false;
        for(auto ast : asts)
        {
            if(st.empty())
            {
                st.push(ast);
            }
            else
            {
                canStop=false;
                while(!canStop)
                {
                    if(st.empty())
                    {
                        st.push(ast);
                        break;
                    }
                    if(st.top()>0 && ast < 0)
                    {
                        if(st.top() > abs(ast))
                        canStop=true;
                        else if(st.top() < abs(ast))
                        st.pop();
                        else
                        {
                            st.pop();
                            canStop=true;
                        }
                    }
                    else
                    {
                        st.push(ast);
                        canStop=true;
                    }

                }
            }
        }

        while(!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }

        reverse(ans.begin(),ans.end());
        return ans;
    }
};
