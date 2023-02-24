// Link :- https://leetcode.com/problems/reverse-string/description/?envType=study-plan&id=algorithm-i


// Code :- 

class Solution {
public:
    void reverseString(vector<char>& s) {
        int l=0;
        int r=s.size()-1;

        while(l<r)
        {
            swap(s[l],s[r]);
            l++;
            r--;
        }
    }
};
