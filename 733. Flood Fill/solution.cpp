// Link :- https://leetcode.com/problems/flood-fill/description/?envType=study-plan&id=algorithm-i



// Code :- 

class Solution {
public:
    
    

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        queue<pair<int,int>> q;
        int n=image.size();
        int m=image[0].size();
        vector<vector<int>> visited(n , vector<int> (m, 0));
        pair<int,int> location;
        int row,col;
        int match_color=image[sr][sc];
        q.push(make_pair(sr,sc));
        int old_color=image[sr][sc];
        while(!q.empty()){
            
            location=q.front();
            row=location.first;
            col=location.second;

            if(!visited[row][col]){
            image[location.first][location.second]=color;
            visited[location.first][location.second]++;

            // now push other elements

            if(row>0)
            {
                if(image[row-1][col]==match_color && !visited[row-1][col])
                {
                    q.push(make_pair(row-1,col));
                }
            }
            if(row<n-1)
            {
                if(image[row+1][col]==match_color  && !visited[row+1][col])
                {
                    q.push(make_pair(row+1,col));
                }
            }
            if(col>0)
            {
                if(image[row][col-1]==match_color && !visited[row][col-1])
                {
                    q.push(make_pair(row,col-1));
                }
            }
            if(col<m-1)
            {
                if(image[row][col+1]==match_color && !visited[row][col+1])
                {
                    q.push(make_pair(row,col+1));
                }
            }
            }
            q.pop();
        }
        return image;
    }
};
