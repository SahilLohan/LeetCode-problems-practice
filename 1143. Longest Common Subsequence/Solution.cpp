// Link : https://leetcode.com/problems/longest-common-subsequence/


// Code : 
/*******************************************************************
************************* Top-Down approach ******************************
*******************************************************************/

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int rows = text1.length();
        int cols = text2.length();

        // initialization

        int dp[rows+1][cols+1];
        memset(dp,0,sizeof(dp));

        // all set
        for(int i=1;i<=rows;i++)
        {
            for(int j=1;j<=cols;j++)
            {
                if(text1[i-1] == text2[j-1])
                {
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else
                {
                    dp[i][j] = max(dp[i-1][j] , dp[i][j-1]);
                }
            }
        }

        return dp[rows][cols];
    }
};


/*******************************************************************
******************** Memoization (Bottom-Up) ***********************
*******************************************************************/

// class Solution {
// public:
//     int dp[1002][1002];

//     int solve(int i,string& a,int j,string& b)
//     {
//         if(dp[i][j]!=-1) return dp[i][j];

//         if(a.length()-i==0 || b.length()-j==0)
//         {
//             dp[i][j]=0;
//             return 0;
//         }

//         if(a[i]==b[j])
//         {
//             dp[i][j] = 1 + solve(i+1,a,j+1,b);
//         }
//         else
//         {
//             dp[i][j] = max(solve(i,a,j+1,b) , solve(i+1,a,j,b));
//         }

//         return dp[i][j];
//     }
//     int longestCommonSubsequence(string s1, string s2) {
//         int i=0;
//         int j=0;
//         memset(dp,-1,sizeof(dp));
//         return solve(i,s1,j,s2);
//     }
// };

// class Solution {
// public:
    
//     int solve(int i,string& a,int j,string& b)
//     {
//         if(a.length()-i==0 || b.length()-j==0)
//             return 0;

//         if(a[i]==b[j])
//         {
//             return 1 + solve(i+1,a,j+1,b);
//         }
//         else
//         {
//             return max(solve(i,a,j+1,b) , solve(i+1,a,j,b));
//         }
//     }
//     int longestCommonSubsequence(string s1, string s2) {
//         int i=0;
//         int j=0;

//         return solve(i,s1,j,s2);
//     }
// };
