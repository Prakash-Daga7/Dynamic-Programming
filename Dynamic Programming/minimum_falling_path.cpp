/*

https://leetcode.com/problems/minimum-falling-path-sum/

*/

class Solution {
public:

  int func(vector<vector<int>>&matrix,int i,int j,int m,int n)
  { 
      if(j<0|| i<0 || i>m || j>n) return INT_MAX;
      if(i==m) return matrix[i][j];
      return matrix[i][j]+min(func(matrix,i+1,j-1,m,n),min(func(matrix,i+1,j,m,n),func(matrix,i+1,j+1,m,n)));
  }

 int minFallingPathSum(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        int mini=INT_MAX;
        for(int j=0;j<n;j++)
        {
            mini=min(mini,func(matrix,0,j,m-1,n-1));
        }
       return  mini;

    }
};


/* Tabular */

 int minFallingPathSum(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
    vector<vector<int>>dp(m,vector<int>(n,-1));
    dp[0][0]=matrix[0][0];
    for(int j=0;j<n;j++)
    {
        dp[0][j]=matrix[0][j];
    }
    for(int i=1;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(j==0)
            {
                dp[i][j]=matrix[i][j]+min(dp[i-1][j],dp[i-1][j+1]);
            }
            else if(j==n-1)
            {
                dp[i][j]=matrix[i][j]+min(dp[i-1][j-1],dp[i-1][j]);
            }
            else
            {
                dp[i][j] = matrix[i][j] + min(dp[i-1][j-1],
                                                min(dp[i-1][j],dp[i-1][j+1]));
            }
            
        }
    }
    int ans=INT_MAX;
   for(int j=0;j<n;j++)
        {
            ans = min(ans,dp[m-1][j]);
        }
        return ans;

    }