class Solution {
public:

    bool repeatedSubstringPattern(string s) {
        if(s.length() <=1) return false;
        int j=0;

        int len;
        int nextStringKiStartingIndex;
        string s1;
        while(j<s.length()/2)
        {
            if(s.length()%(j+1)==0) // is this string repating
            {
                len = j+1;
                s1 = s.substr(0,len);
                nextStringKiStartingIndex = j+1;

                while(nextStringKiStartingIndex < s.length())
                {
                    if(s1 == s.substr(nextStringKiStartingIndex,len))
                        nextStringKiStartingIndex += j+1;
                    else
                        break;
                }
                if(nextStringKiStartingIndex == s.length())
                    return true;
            }
            j++;
        }

        return false;
    }
};
