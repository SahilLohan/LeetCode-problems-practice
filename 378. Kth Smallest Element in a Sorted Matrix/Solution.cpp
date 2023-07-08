// Link : https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/

// Code :
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<int> pq;

        for(int i=0;i<matrix.size();i++)
        {
            for(int j=0;j<matrix[0].size();j++)
            {
                pq.push(matrix[i][j]);
                if(pq.size()>k)
                {
                    pq.pop();
                }
            }
        }
        return pq.top();
    }
};
