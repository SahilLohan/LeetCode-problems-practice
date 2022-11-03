// link :- https://leetcode.com/problems/longest-palindrome-by-concatenating-two-letter-words/description/


class Solution {
public:
    string reverseOf(string str)
    {
        swap(str[0],str[1]);
        return str;
    }

    bool isPalindrome(string& str)
    {
        return str[0]==str[1];
    }

    int longestPalindrome(vector<string>& words) 
    {
        map<string,int> nmp;
        map<string,int> pmp;
        int count=0;
        int flag=0;
        for(int i=0;i<words.size();i++)
        {
            if(isPalindrome(words[i]))
            {
                ++pmp[words[i]];
            }
            else 
            {
                ++nmp[words[i]];
            }
            
        }

        for(auto e:nmp)
        {
            count+=2*min(nmp[e.first],nmp[reverseOf(e.first)]);
        }


        flag=0;
        for(auto e:pmp)
        {
            if(pmp[e.first]>0)
            {
                if(pmp[e.first]%2==0 ) // even
                {
                    count+=(2*pmp[e.first]);
                }
            }
        }

        for(auto e:pmp)
        {
            if(pmp[e.first]>0)
            {
                if(pmp[e.first]%2!=0 ) // odd
                {
                    if(flag==0)
                    {
                        count+=(2*pmp[e.first]);
                        flag++;
                    }
                    else{
                        count+=(2*(pmp[e.first]-1));
                    }
                }
            }
        }


        return count;
    }
};
