// Link : https://leetcode.com/problems/sudoku-solver/


// Code :
class Solution {
public:
    bool isPossibleChoice(int r,int c,char ch,vector<vector<char>>& board)
    {
        // poori row m same cheej h ya nhi 
        for(int i=0;i<9;i++)
        {
            if(board[r][i]==ch)
            return false;
        }

        // poori column m same cheej h ya nhi
        for(int i=0;i<9;i++)
        {
            if(board[i][c]==ch)
            return false;
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
                if(board[i][j]==ch)
                return false;
            }
        }

        return true;

    }

    bool solve(int r,int c,vector<vector<char>>& board)
    {

        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {
                if(board[i][j]=='.')
                {
                    for(auto ch='1';ch<='9';ch++)
                    {
                        if(isPossibleChoice(i,j,ch,board))
                        {
                            board[i][j]=ch;
                            if(solve(i,j,board))
                            {
                                return true;
                            }
                            else
                            board[i][j]='.';
                        }
                    }
                    return false;
                }
                
            }
        }

        return true;
    }

    void solveSudoku(vector<vector<char>>& board) {
        int r=0,c=0;
        bool possible = solve(r,c,board);
        // one solution always exist
    }
};
