// Link : https://leetcode.com/problems/valid-sudoku/


// Code :
class Solution {
public:
bool isPossibleChoice(int r,int c,char ch,vector<vector<char>>& board)
    {
        // poori row m same cheej h ya nhi 
        for(int i=0;i<9;i++)
        {
            if(board[r][i]==ch && i!=c)
            {
                cout << "Error in row\n";
                return false;
            }
        }

        // poori column m same cheej h ya nhi
        for(int i=0;i<9;i++)
        {
            if(board[i][c]==ch && i!=r)
            {
                cout << "Error in column\n";
                return false;
            }
            
        }

        // poore sub block m same cheej h ye nhi
        int quo;
        quo=r/3;

        int r_start= 3*quo;
        int r_end=r_start+3;

        quo=c/3;

        int c_start= 3*quo;
        int c_end=c_start+3;

        for(int i=r_start;i<r_end;i++)
        {
            for(int j=c_start;j<c_end;j++)
            {
                if(board[i][j]==ch && i!=r && j!=c)
                {
                    cout << "Error in subblock\n";
                    return false;
                }
                
            }
        }

        return true;

    }

    bool isValidSudoku(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(board[i][j]!='.')
                {
                    if(!isPossibleChoice(i,j,board[i][j],board))
                    {
                        cout << "knha h gadbad\n";
                        return false;
                    }
                    
                }
            }
        }
        return true;
    }
};
