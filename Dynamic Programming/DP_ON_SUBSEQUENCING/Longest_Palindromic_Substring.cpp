/* https://leetcode.com/problems/longest-palindromic-substring/description/ */


class Solution {
public:
    string longestPalindrome(string s) {
        string ans="";
        ans=ans+s[0];
        int n=s.size();
        if(n==0) return "";

        //bool dp[n][n];
        int maxi=1; //length
        int start=0;
       vector<vector<bool>>dp(n,vector<bool>(n,0));
       for(int i=0;i<n;i++)
       {
           dp[i][i]=true;
       }
      // string ans="";
       for(int i=0;i<n-1;i++)
       {
           if(s[i]==s[i+1])
           {
              dp[i][i+1]=1;
              start=i;
              maxi=2;
           }
       }
      
       for(int k=3;k<=n;k++)
       {
          for(int i=0;i<n-k+1;i++)
          {
              int j=i+k-1;

              if(s[i]==s[j] && dp[i+1][j-1]==1)
              {
                  dp[i][j]=1;
                  start=i;
                  maxi=k;

                  
              }
          }

       }
       return s.substr(start,maxi);
    }
};