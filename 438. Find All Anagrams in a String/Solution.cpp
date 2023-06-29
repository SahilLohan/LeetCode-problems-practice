// Link : https://leetcode.com/problems/find-all-anagrams-in-a-string/


// Code :
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {


        vector<int> ans;

        if(s.length() < p.length())
            return ans;

        int i=0,j=p.length()-1,n=s.length();

        unordered_map<char,int> mp,mp1;
        for(int x=i;x<j;x++)
        {
            mp[s[x]]++;    
        }
        for(auto ch:p)
        {
            mp1[ch]++;
        }

        while(j<n)
        {
            mp[s[j]]++;

            for(auto e=mp1.begin() ; e!=mp1.end() ;)
            {
                if(mp[e->first] != e->second)
                    break;

                e++;
                if(e==mp1.end())
                {
                    ans.push_back(i);
                }
            }
            
            mp[s[i]]--;

            i++;
            j++;
        }
        return ans;
    }
};
