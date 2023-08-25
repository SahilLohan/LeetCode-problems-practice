// Link : https://leetcode.com/problems/shortest-completing-word/description/


// Code : 
class Solution {
public:
    bool match(string word,unordered_map<char,int>& lp)
    {
        // cout << "word to br matched : " << word <<endl;
        unordered_map<char,int> mp;
        for(auto ch:word)
        {
            if(lp.find(ch)!=lp.end() && lp[ch]>mp[ch])
            {
                mp[ch]++;
            }
        }

        if(mp==lp) return true;
        return false;
    }
    string shortestCompletingWord(string plate, vector<string>& words) {
        unordered_map<char,int> lp;
        string ans="";
        for(auto ch:plate)
        {
            if((ch>='a' && ch <='z') || (ch>='A' && ch<='Z'))
            {
                ch = tolower(ch);
                lp[ch]++;
            }
        }

        // now we have all chararater of plate in map

        for(auto word:words)
        {
            if((ans.length()==0 || word.length()<ans.length()) && match(word,lp))
            {
                // cout << "word : " << word << " ans : " << ans << endl;
                ans = word;
            }
        }

        return ans;
    }
};
