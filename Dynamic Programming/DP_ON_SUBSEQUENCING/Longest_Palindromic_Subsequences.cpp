
/* https://practice.geeksforgeeks.org/problems/longest-palindromic-subsequence-1612327878/0 */

 int longestPalinSubseq(string a) {
        //code here
        
        int x=a.length();
       int  y=a.length();
       string s1=a;
       string s2=a;
       reverse(s2.begin(),s2.end());
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

