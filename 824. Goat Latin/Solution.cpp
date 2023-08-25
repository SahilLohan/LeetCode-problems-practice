// Link : https://leetcode.com/problems/goat-latin/description/


// Code :
class Solution {
public:
    bool isVowel(char ch)
    {
        ch = tolower(ch);
        return ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u';
    }
    string toGoatLatin(string s) {
        string temp="";
        bool flag=false;
        string ma="maa";
        string ans="";
        for(int j=0;j<s.length();j++)
        {
            if(s[j]==' ')
            {
                if(flag==true)
                    ans = ans + temp + ma + s[j];
                else
                    ans = ans + ma + s[j];
                
                ma = ma+"a";
                flag = false;
            }
            else if(j==0 && !isVowel(s[j]))
            {
                flag =true;
                temp = s[j];
            }
            else if(j>0 && s[j-1]==' ' && isVowel(s[j]))
            {
                ans += s[j];
            }
            else if(j>0 && s[j-1]==' ' && !isVowel(s[j]))
            {
                flag =true;
                temp = s[j];
            }
            else
            {
                ans += s[j];
            }
        }

        if(flag)
        {
            ans = ans + temp + ma ;
        }
        else
        {
            ans = ans + ma ;
        }

        return ans;
    }
};
