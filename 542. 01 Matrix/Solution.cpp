// Link :- https://leetcode.com/problems/01-matrix/description/

// Code :- 

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        vector<vector<int>> visited(m,vector<int>(n,0));
        vector<vector<int>> distance(m,vector<int>(n,0));
        queue<pair<pair<int,int>,int>> q;
        pair<pair<int,int>,int> loc;

        int r,c,d;
        for(int i = 0;i<m;i++)
        {
            for(int j = 0;j<n;j++)
            {
               if(mat[i][j] == 0)
               {

               q.push(make_pair(make_pair(i,j),0));
               distance[i][j] = 0;
               visited[i][j]++;
            }}
        }

        while(!q.empty())
        {
            loc = q.front();
            r = loc.first.first;
            c = loc.first.second;
            d = loc.second;
            // cout << "Queue front is ("<< r << "," << c << ")," << d << endl; 
            distance[r][c] = d;
            q.pop();

            // push sirf unvisited ko hi krna h 

            // lets go up
            if(r>0)
            {
                if(!visited[r-1][c])
                {
                    q.push(make_pair(make_pair(r-1,c),d+1));
                    visited[r-1][c]++;
                }
            }

            // lets go down
            if(r<m-1)
            {
                if(!visited[r+1][c])
                {
                    q.push(make_pair(make_pair(r+1,c),d+1));
                    visited[r+1][c]++;
                }
            }

            // left go left
            if(c>0)
            {
                if(!visited[r][c-1])
                {
                    q.push(make_pair(make_pair(r,c-1),d+1));
                    visited[r][c-1]++;
                }
            }

            // lets go right
            if(c<n-1)
            {
                if(!visited[r][c+1])
                {
                    q.push(make_pair(make_pair(r,c+1),d+1));
                    visited[r][c+1]++;
                }
            }
        }

        return distance;

    }
};
