// Link :- https://leetcode.com/problems/rotting-oranges/description/


// Code :- 


class Solution {
public:
    int orangesRotting(vector<vector<int>>& orng) {
        
        int m = orng.size();
        int n = orng[0].size();
        vector<vector<int>> rottenat(m,vector<int>(n,-1));
        queue<pair<pair<int,int>,int>> q;

        int fr=0,ro=0;
        int minutes=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(orng[i][j]==1)
                {
                    q.push(make_pair(make_pair(i,j),1));
                    fr++;
                }
                else if(orng[i][j]==2)
                {
                rottenat[i][j]=0;
                ro++;
                }
            }
        }

        int initial_size_of_queue=q.size();
        int initial_time=1;
        pair<pair<int,int>,int> loc; 
        int r,c,min;
        int temp=0;
        while(!q.empty())
        {
            //cout << "Size of q is " << q.size() << endl;
            
            // Lets take out the front element

            loc=q.front();
            r=loc.first.first;
            c=loc.first.second;
            min=loc.second;
            temp=0;
            minutes=min;

            if(initial_time+1==min)
            {
                if(initial_size_of_queue==q.size())
                {
                    return -1;
                }
                else
                {
                    initial_time++;
                    initial_size_of_queue=q.size();
                }
            }
            //cout <<"minute : "<<  minutes << " ----   Elements in queue : "<< q.size()<< endl;
            q.pop();

            // all adjacent are empty

            if(r>0)
            {
                if(orng[r-1][c]==2 && rottenat[r-1][c]!=min)
                {
                    orng[r][c]=2;
                    rottenat[r][c]=min;
                    continue;
                }
                else if(orng[r-1][c]==0)
                {
                    temp++;
                }
            }
            else
            temp++;
            if(r<m-1)
            {
                if(orng[r+1][c]==2 && rottenat[r+1][c]!=min)
                {
                    orng[r][c]=2;
                    rottenat[r][c]=min;
                    continue;
                }
                else if(orng[r+1][c]==0)
                {
                    temp++;
                }
            }
            else
            temp++;
            if(c>0)
            {
                if(orng[r][c-1]==2 && rottenat[r][c-1]!=min)
                {
                    orng[r][c]=2;
                    rottenat[r][c]=min;
                    continue;
                }
                else if(orng[r][c-1]==0)
                {
                    temp++;
                }
            }
            else
            temp++;
            if(c<n-1)
            {
                if(orng[r][c+1]==2 && rottenat[r][c+1]!=min)
                {
                    orng[r][c]=2;
                    rottenat[r][c]=min;
                    continue;
                }
                else if(orng[r][c+1]==0)
                {
                    temp++;
                }
            }
            else
            temp++;

            if(temp==4)
            return -1;

            q.push(make_pair(make_pair(r,c),min+1));

        }

        return minutes;
    }
};
