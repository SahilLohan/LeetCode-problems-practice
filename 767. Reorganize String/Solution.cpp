// Link : https://leetcode.com/problems/reorganize-string/description/


// Code :
class Solution {
public:
    int find(int i,string s)
    {
        int index =i+1;
        while(index<s.length() && s[index]==s[i])
        {
            index++;
        }
        return index;
    }
    string reorganizeString(string s) {
        int index=0;
        bool flag = false;
        for(int i=1;i<s.length();i++)
        {
            if(s[i]==s[i-1])
            {
                index = find(i,s);
                if(index>=s.length())
                flag=true;
                else
                {
                    swap(s[i],s[index]);
                }
            }
        }
        if(flag)
        {
            reverse(s.begin(),s.end());
            for(int i=1;i<s.length();i++)
            {
                if(s[i]==s[i-1])
                {
                    index = find(i,s);
                    if(index>=s.length())
                    return "";
                    else
                    {
                        swap(s[i],s[index]);
                    }
                }
            }
        }

        return s;
    }
};
