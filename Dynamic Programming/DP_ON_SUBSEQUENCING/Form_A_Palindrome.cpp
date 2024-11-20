/* https://practice.geeksforgeeks.org/problems/form-a-palindrome2544/1 */

 int findMinInsertions(string a){
        // code here 
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
        
        return x- dp[x][y];
    }

/*
  ABCD - LONGEST PALINDROMIC LENGTH = 1  , MIN INSERTIONS = 3(LENGTH-1)
    AACECAAAA - LONGEST PALINDROMIC LENGTH = 7 , MIN INSERTIONS = 3(LENGTH-7)
*/