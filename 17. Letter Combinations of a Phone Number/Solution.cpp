// Link for problem :- https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/

// code --->

// current solution

class Solution {
    unordered_map<char,string> mp;
    string digits="";
    vector<string> ans;
    
public:
    Solution()
    {
        mp['1']="";
        mp['2']="abc";
        mp['3']="def";
        mp['4']="ghi";
        mp['5']="jkl";
        mp['6']="mno";
        mp['7']="pqrs";
        mp['8']="tuv";
        mp['9']="wxyz";
    }

    void solve(int index,string pattern)
    {
        if(index==digits.length())
        {
            ans.push_back(pattern);
            return;
        }
        else
        {
            string alphabets = mp[digits[index]];
            for(auto alphabet:alphabets)
            {
                solve(index+1,pattern+alphabet);
            }
        }
    }

    vector<string> letterCombinations(string digits) {
        if(digits.length()==0)
        return ans;
        
        this->digits = digits;
        int index=0;
        string pattern="";
        solve(index,pattern);
        return ans;
    }
};







// old solution
class Solution {
private:
    string two="abc";
    string three="def";
    string four="ghi";
    string five="jkl";
    string six="mno";
    string seven="pqrs";
    string eight="tuv";
    string nine="wxyz";
public:

    vector<string> result;
    void push(string cases,string digits,int curr_index=0)
    {
        if(curr_index==digits.length())
        {
            result.push_back(cases);
            return;
        }
        else
        {
            if(digits[curr_index]=='2')
            {
                for(int i=0;i<two.length();i++)
                {
                    cases.push_back(two[i]);
                    push(cases,digits,curr_index+1);
                    cases.pop_back();
                }
            }
            if(digits[curr_index]=='3')
            {
                for(int i=0;i<three.length();i++)
                {
                    cases.push_back(three[i]);
                    push(cases,digits,curr_index+1);
                    cases.pop_back();
                }
            }
            if(digits[curr_index]=='4')
            {
                for(int i=0;i<four.length();i++)
                {
                    cases.push_back(four[i]);
                    push(cases,digits,curr_index+1);
                    cases.pop_back();
                }
            }
            if(digits[curr_index]=='5')
            {
                for(int i=0;i<five.length();i++)
                {
                    cases.push_back(five[i]);
                    push(cases,digits,curr_index+1);
                    cases.pop_back();
                }
            }
            if(digits[curr_index]=='6')
            {
                for(int i=0;i<six.length();i++)
                {
                    cases.push_back(six[i]);
                    push(cases,digits,curr_index+1);
                    cases.pop_back();
                }
            }
            if(digits[curr_index]=='7')
            {
                for(int i=0;i<seven.length();i++)
                {
                    cases.push_back(seven[i]);
                    push(cases,digits,curr_index+1);
                    cases.pop_back();
                }
            }
            if(digits[curr_index]=='8')
            {
                for(int i=0;i<eight.length();i++)
                {
                    cases.push_back(eight[i]);
                    push(cases,digits,curr_index+1);
                    cases.pop_back();
                }
            }
            if(digits[curr_index]=='9')
            {
                for(int i=0;i<nine.length();i++)
                {
                    cases.push_back(nine[i]);
                    push(cases,digits,curr_index+1);
                    cases.pop_back();
                }
            }
        }
    }

    vector<string> letterCombinations(string digits) {
        
        if(digits.length()==0)
        {
            vector<string> ans;
            return ans;
        }

        string cases;
        push(cases,digits);
        
        return result;
    }
};
