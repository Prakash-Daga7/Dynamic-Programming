 /*
    Link:-https://leetcode.com/problems/unique-paths-ii/description/
 */
 
 /* recursion*/
 int func(int i,int j,vector<vector<int>>&dp,vector<vector<int>>& obstacleGrid)
   {
       if(i>=0 && j>=0 && obstacleGrid[i][j]==1 ) return 0;
       if(i==0 && j==0) return 1;
       if(i<0 || j<0) return 0;
       if(dp[i][j]!=-1) return dp[i][j];
       int up=func(i-1,j,dp,obstacleGrid);
       int left=func(i,j-1,dp,obstacleGrid);
       return dp[i][j]=(up+left)%1000000009;
   }
   
  

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return func(n-1,m-1,dp,obstacleGrid)%1000000009;
    }

/* dp */

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        int dp[m][n];
    ///func(m-1,n-1,dp);
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i>=0 && j>=0 && obstacleGrid[i][j]==1) dp[i][j]= 0;
            
           else if(i==0 &&j==0) dp[i][j]=1;
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
};