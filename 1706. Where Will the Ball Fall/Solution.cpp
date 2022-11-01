// Link :- https://leetcode.com/problems/where-will-the-ball-fall/description/

class Solution {
public:

    int solve(vector<vector<int>>& grid,int row,int col,int m ,int n)
    {
        while(row!=m)
        {
            if(grid[row][col]==1) // right side jana h 
            {
                if(col==n-1)
                {
                    return -1;
                }
                else if(grid[row][col+1]==-1)
                {
                    return -1;
                }
                else{
                    col++;
                    row++;
                }
            }
            else if(grid[row][col]==-1) // left side jana h 
            {
                if(col==0)
                {
                    return -1;
                }
                else if(grid[row][col-1]==1)
                {
                    return -1;
                }
                else{
                    col--;
                    row++;
                }
            }
        }
        return col;
    }
    vector<int> findBall(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();

        vector<int> answer(n,-2);

        for(int k=0;k<n;k++)
        {
            // solve for every column
            answer[k]=solve(grid,0,k,m,n);
        }
        return answer;
    }
};
