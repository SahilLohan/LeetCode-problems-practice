// Link : https://leetcode.com/problems/longest-repeating-character-replacement/description/


// Code :
class Solution {
public:
    int characterReplacement(string s, int k) {
        
        int ans=0;
        int len;
        int n=s.length();
        char ch;
        int j;
        int chance;

        for(int i=0;i<n;i++)
        {
            //cout << "i : " << i << " ch :" << s[i] << endl;
            len=0;
            ch=s[i];
            j=i;
            chance=k;
            //cout << "chances : " << chance << endl;

            while(j<n && (s[j]==ch || chance>0))
            {
                //cout << "s[j] : " << s[j] << endl;
                if(s[j]!=ch)
                chance--;

                j++;
                len++;
            }

            if(len<n && chance!=0)
            {
                if(n-len < chance)
                {
                    len += n-len;
                }
                else
                {
                    len +=chance;
                }
            }

            if(len>ans) ans=len;

            //cout << "ans : " << ans << endl;
        }

        return ans;
    }
};
