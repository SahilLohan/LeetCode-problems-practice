// Link :- https://leetcode.com/problems/max-area-of-island/description/?envType=study-plan&id=algorithm-i


// code :- 

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int max=0,area;
        vector<vector<int>> visited(grid.size(),vector<int>(grid[0].size(),0));
        int n=grid.size();
        int m=grid[0].size();

        queue<pair<int,int>> q;
        int row,col;

        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[i].size();j++)
            {

                if(!visited[i][j] && grid[i][j]==1)
                {
                    q.push(make_pair(i,j));
                    pair<int,int> location;
                    area=0;
                    while(!q.empty()){
                        
                        location=q.front();
                        row=location.first;
                        col=location.second;

                        if(!visited[row][col]){
                            visited[location.first][location.second]++;
                            area++;

                            // now push other elements

                            if(row>0)
                            {
                                if(grid[row-1][col]==1 && !visited[row-1][col])
                                {
                                    q.push(make_pair(row-1,col));
                                }
                            }
                            if(row<n-1)
                            {
                                if(grid[row+1][col]==1  && !visited[row+1][col])
                                {
                                    q.push(make_pair(row+1,col));
                                }
                            }
                            if(col>0)
                            {
                                if(grid[row][col-1]==1 && !visited[row][col-1])
                                {
                                    q.push(make_pair(row,col-1));
                                }
                            }
                            if(col<m-1)
                            {
                                if(grid[row][col+1]==1 && !visited[row][col+1])
                                {
                                    q.push(make_pair(row,col+1));
                                }
                            }
                        }
                        q.pop();
                    }
                    if(area>max) max=area;
                }
            }    
        }

        return max;
        
    }
};
