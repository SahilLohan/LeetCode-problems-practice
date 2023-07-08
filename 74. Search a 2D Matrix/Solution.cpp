// Link : https://leetcode.com/problems/search-a-2d-matrix/


// Code :
class Solution {
public:

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int mid;
        int l=0,h=m*n -1;
        // Binary search in matrix
        while(l<=h)
        {
            mid = l+ (h-l)/2;
            if(matrix[mid/n][mid%n]==target)
            {
                return true;
            }
            else if(matrix[mid/n][mid%n]<target)
            {
                l=mid+1;
            }
            else
            {
                h=mid-1;
            }
        }
        return false;
    }
};
