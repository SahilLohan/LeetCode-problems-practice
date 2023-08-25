// Link : https://leetcode.com/problems/merge-strings-alternately/description/


// Code :
class Solution {
public:
    string mergeAlternately(string w1, string w2) {
        int i=0,j=0;
        string ans="";

        while(i<w1.length() && j<w2.length())
        {
            if(i>=w1.length() || j>=w2.length())
            break;
            ans += w1[i];
            ans += w2[j];
            i++;
            j++;
        }

        while(i<w1.length())
        {
            if(i>=w1.length())
            break;
            ans+=w1[i];
            i++;
        }

        while(j<w2.length())
        {
            if(j>=w2.length())
            break;
            ans+=w2[j];
            j++;
        }

        return ans;
    }
};
