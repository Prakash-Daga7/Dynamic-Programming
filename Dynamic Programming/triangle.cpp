/*
       https://leetcode.com/problems/triangle/
*/

/* Recursion */

class Solution {
public:

   int func(int i,int j,vector<vector<int>>&triangle,int n)
   {
       if(i==(n-1)) return triangle[n-1][j];
       if(i<0 || j<0) return 0;

       int one=triangle[i][j]+func(i+1,j,triangle,n);
       int two=triangle[i][j]+func(i+1,j+1,triangle,n);
       return min(one,two);

   }

    int minimumTotal(vector<vector<int>>& triangle) {
        
        int n=triangle.size();
        int m=triangle[0].size();

        return func( 0, 0,triangle,n);

    }
};

/* dp */

class Solution {
public:

   int func(int i,int j,vector<vector<int>>&triangle,int n,vector<vector<int>>&dp)
   {
       if(i==(n-1)) return triangle[n-1][j];
       if(i<0 || j<0) return 0;
     if(dp[i][j]!=-1) return dp[i][j];
       int one=triangle[i][j]+func(i+1,j,triangle,n,dp);
       int two=triangle[i][j]+func(i+1,j+1,triangle,n,dp);
       return dp[i][j]=min(one,two);

   }

    int minimumTotal(vector<vector<int>>& triangle) {
        
        int n=triangle.size();
        int m=triangle[0].size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return func( 0, 0,triangle,n,dp);

    }
};