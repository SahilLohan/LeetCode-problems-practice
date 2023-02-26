// Link :- https://leetcode.com/problems/permutation-in-string/description/?envType=study-plan&id=algorithm-i


// Code :- 


class Solution {
private:
    bool permutation_exist(map<char,int> &mp,int start,int end,string s2)
    {
        map<char,int> mp2;
        while(start<end){
            mp2[s2[start]]++;    
            start++;
        }
        if(mp==mp2)
        return true;
        else
        return false;
    }


public:
    bool checkInclusion(string s1, string s2) {
        if(s1.length()==0) return true;
        if(s1.length()>s2.length()) return false;

        int length1=s1.length();
        int length2=s2.length();

        map<char,int> mp;
        for(auto ch : s1){
            mp[ch]++;
        }

        int ptr=0;

        while(ptr<=length2-length1){
            if(mp[s2[ptr]]!=0)
            {
                if(permutation_exist(mp,ptr,ptr+length1,s2))
                return true;
            }
            else{
                mp.erase(s2[ptr]);
            }

            ptr++;
        }

        return false;

    }
};
