// Link :- https://leetcode.com/problems/first-unique-character-in-a-string

// code :-

class Solution {
public:
    int firstUniqChar(string s) {
        queue<int> q;
        map<char,int> mp;
        for(int i=0;i<s.length();i++)
        {
            ++mp[s[i]];
            if(mp[s[i]]==1)
            {
                q.push(i);
            }
        }

        while(!q.empty())
        {
            if(mp[s[q.front()]]==1)
            {
                return q.front();
            }
            q.pop();
        }
        return -1;
    }
};
