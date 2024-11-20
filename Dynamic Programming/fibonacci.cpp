  
  long long int func(vector<long long int>&dp,long long int n)
   {
       if(n<=1) return n;
       if(dp[n]!=-1) return dp[n];
       return dp[n]=(func(dp,n-1)+func(dp,n-2))%1000000007;
   }
  
    long long int nthFibonacci(long long int n){
        // code here
        vector<long long int> dp(n+1,-1);
        func( dp, n);
        return dp[n]%1000000007;
    }
//TC: O(n) 
//SC: O(n)+O(n) for stack

/**************  OPTIMIZE   space complexity      *******************/

 long long int nthFibonacci(long long int n){
        // code here
        vector<long long int> dp(n+1,-1);
      dp[0]=0;
      dp[1]=1;
      for(int i=2;i<=n;i++)
      {
          dp[i]=dp[i-1]+dp[i-2]%1000000007;
      }
        return dp[n]%1000000007;
    }

    //TC: O(n)
    //SC: O(n) 