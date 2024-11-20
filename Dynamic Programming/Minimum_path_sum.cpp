/*
  Link:- https://leetcode.com/problems/minimum-path-sum/description/
*/

/* Recursion */
class Solution {
public:
   
   int func(int i,int j,vector<vector<int>>&grid)
   {
       if(i==0 && j==0) return grid[i][j];
       if(i<0 || j<0) return 1e9;

       int up=grid[i][j]+func(i-1,j,grid);
       int left=grid[i][j]+func(i,j-1,grid);
       return min(up,left);
  }

    int minPathSum(vector<vector<int>>& grid)   
    {
        int n=grid.size();
        int m=grid[0].size();
       return  func(n-1,m-1,grid);
    }
};

/* dp */

class Solution {
public:
   
   int func(int i,int j,vector<vector<int>>&grid,vector<vector<int>>&dp)
   {
       if(i==0 && j==0) return grid[i][j];
       if(i<0 || j<0) return 1e9;
       if(dp[i][j]!=-1) return dp[i][j];
       int up=grid[i][j]+func(i-1,j,grid,dp);
       int left=grid[i][j]+func(i,j-1,grid,dp);
       return dp[i][j]=min(up,left);
  }

    int minPathSum(vector<vector<int>>& grid)   
    {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
       return  func(n-1,m-1,grid,dp);
    }
};

