// Link :- https://leetcode.com/problems/reverse-vowels-of-a-string/description/


// code --->


class Solution {
public:
    bool isVowel(char ch)
    {
        if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u' || ch=='A' || ch=='E' || ch=='I' || ch=='O' || ch=='U')
        {
            return true;
        } 
        return false;
    }

    string reverseVowels(string str) {
        int i=0,j=str.length();

        while(i<j)
        {
            if(isVowel(str[i]) && isVowel(str[j]))
            {
                swap(str[i],str[j]);
                i++;
                j--;
            }
            else
            {
                if(!isVowel(str[i]))
                {
                    i++;
                }
                if(!isVowel(str[j]))
                {
                    j--;
                }
            }
        }
        return str;
    }
};
