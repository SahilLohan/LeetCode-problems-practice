// Link : https://leetcode.com/problems/interleaving-string/


// Code : 

class Solution {
public:
    int dp[101][101];
    int solveInterleave(string& s1, string& s2, string& s3,int i=0,int j=0,int k=0) {
        if(dp[i][j]!= -1) return dp[i][j];
        else
        {
            if(i==s1.length() && j==s2.length() && k==s3.length())
            {
                return dp[i][j]=1;
            }
            
            // choices
            if(i<s1.length() && s1[i]==s3[k] && solveInterleave(s1,s2,s3,i+1,j,k+1)) return dp[i][j]=1;

            if(j<s2.length() && s2[j]==s3[k] && solveInterleave(s1,s2,s3,i,j+1,k+1)) return dp[i][j]=1;

            return dp[i][j]=0;
        }
    }

    bool isInterleave(string s1,string s2,string s3)
    {
        if(s1.length()+s2.length()!=s3.length()) return false;

        memset(dp,-1,sizeof(dp));
        return solveInterleave(s1,s2,s3,0,0,0)==1?true:false;

    }
};
