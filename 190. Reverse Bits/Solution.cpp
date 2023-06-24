// Link : https://leetcode.com/problems/reverse-bits/description/


// Code :

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t result = 0;
        int bitCount = 32;
        
        while (bitCount--) {
            result <<= 1;   // Left shift result by 1 to make space for the next bit
            
            if (n & 1)      // Check if the least significant bit of n is 1
                result |= 1; // Set the least significant bit of result to 1
            
            n >>= 1;        // Right shift n by 1 to discard the processed bit
        }
        
        return result;
    }
};
