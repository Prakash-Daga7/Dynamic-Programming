
/* https://practice.geeksforgeeks.org/problems/longest-common-subsequence-1587115620/1 */

/* Recursion */
 int f(int ind1,int ind2, string s1,string s2)
    {
        if(ind1<0 || ind2<0)
        {
            return 0;
        }
        
        if(s1[ind1]==s2[ind2])
        {
            return 1+f(ind1-1,ind2-1,s1,s2);
        }
        else
        {
            return 0+max(f(ind1-1,ind2,s1,s2),f(ind1,ind2-1,s1,s2));
        }
    }
    
    //Function to find the length of longest common subsequence in two strings.
    int lcs(int x, int y, string s1, string s2)
    {
        // your code here
        return f(x-1,y-1,s1,s2);
    }


    /* DP */
      int f(int ind1,int ind2, string s1,string s2,vector<vector<int>>&dp)
    {
        if(ind1<0 || ind2<0)
        {
            return 0;
        }
        if(dp[ind1][ind2]!=-1) return dp[ind1][ind2];
        if(s1[ind1]==s2[ind2])
        {
            return 1+f(ind1-1,ind2-1,s1,s2,dp);
        }
        else
        {
            return dp[ind1][ind2]= 0+max(f(ind1-1,ind2,s1,s2,dp),f(ind1,ind2-1,s1,s2,dp));
        }
    }
    
    //Function to find the length of longest common subsequence in two strings.
    int lcs(int x, int y, string s1, string s2)
    {
        // your code here
        vector<vector<int>>dp(x,vector<int>(y,-1));
        return f(x-1,y-1,s1,s2,dp);
    }


    /* Tabular */
     int lcs(int x, int y, string s1, string s2)
    {
        // your code here
       int dp[1001][1001];
        for(int j=0;j<=x;j++) dp[0][j]=0;
        for(int i=0;i<=y;i++) dp[i][0]=0;
        
        for(int i=1;i<=x;i++)
        {
            for(int j=1;j<=y;j++)
            {
                 if(s1[i-1]==s2[j-1])
                 {
                     dp[i][j]=1+dp[i-1][j-1];
                     }
                else
                 {
                     dp[i][j]= max(dp[i-1][j],dp[i][j-1]);
                   }  
               }
        }
        
        return dp[x][y];
    }