/*  
  Link:- https://leetcode.com/problems/unique-paths/description/
  Link2:- https://practice.geeksforgeeks.org/problems/number-of-paths0926/1
*/

/*   RECURSION */
class Solution {
public:
   
   int f(int i,int j)
   {
       if(i==0 && j==0)
        {
            return 1;
        }
        if(i<0||j<0) return 0;
        int up=f(i-1,j);
        int left=f(i,j-1);
        return up+left;
   }

    int uniquePaths(int i, int j) {
        
      return f(i-1,j-1);
    }
};

/* for GFG*/
long long func(int i,int j)
{
    if(i==0 && j==0) return 1;
    if(i<0 || j<0 ) return 0;
    
    int up=func(i-1,j);
    int left=func(i,j-1);
    return up +left;
}

long long  numberOfPaths(int m, int n)
{
    // Code Here
    return func(m-1,n-1);
}


/* DP */

long long func(int i,int j,vector<vector<int>>&dp)
{
    if(i==0 && j==0) return 1;
    if(i<0 || j<0 ) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    int up=func(i-1,j,dp);
    int left=func(i,j-1,dp);
    return dp[i][j]=up +left;
}

long long  numberOfPaths(int m, int n)
{
    // Code Here
    vector<vector<int>>dp(m,vector<int>(n,-1));
    ///func(m-1,n-1,dp);
    return func(m-1,n-1,dp);
}


/* TABULAR */
long long  numberOfPaths(int m, int n)
{
    // Code Here
   int dp[m][n];
    ///func(m-1,n-1,dp);
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
           if(i==0 &&j==0) dp[i][j]=1;
           else
           {
           int up=0;
           int left=0;
           if(i>0) up=dp[i-1][j];
           if(j>0) left=dp[i][j-1];
            dp[i][j]= up+left;
           }
           
        }
    }
    return dp[m-1][n-1];
}