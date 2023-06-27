// Link : https://leetcode.com/problems/number-of-visible-people-in-a-queue/


// Code : 


class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& h) {

        /**********************************************
        ************ TIME LIMIT EXCEEDED **************
        **********************************************/

        // vector<int> ans(h.size());
        // int n = h.size();
        // int temp;
        // for(int i=0 ; i<n ; i++)
        // {
        //     temp=0;
        //     for(int j=i+1;j<n;j++)
        //     {
        //         if(min(h[i],h[j]) > temp)
        //         {
        //             ans[i]++;
        //             temp=h[j];
        //         }
        //     }
        // }
        // return ans;
        int n = h.size();
        vector<int> ans(h.size(),0);
        stack<int> s;
        s.push(h[n-1]);
        int count;
        cout << s.top() << endl;
        for(int i=n-2;i>=0;i--)
        {
            // cout << "i : " << i << endl;
            count=0;
            // cout << s.top() << endl;
            while(!s.empty() && s.top() < h[i])
            {
                // cout << " count : " << count << " because " << s.top() << " < " << h[i] <<endl;
                s.pop();
                count++;
            }
            
            if(!s.empty())
            {
                count++;
                // cout << " count : " << count << endl;
            }
            s.push(h[i]);
            ans[i]=count;

        }

        return ans;
    }
};
