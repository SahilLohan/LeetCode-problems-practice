// Link : https://leetcode.com/problems/number-of-1-bits/

// Code :

class Solution {
public:
    int hammingWeight(uint32_t n) {
        // super level approach Lol !!!

        // bitset<32> num(n);
        // return num.count();

        // real approach
        int count=0;

        while(n){
            n = n&(n-1);
            count++;
        }
        return count;

   }
};
