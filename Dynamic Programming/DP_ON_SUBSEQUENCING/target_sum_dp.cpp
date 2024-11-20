

/*  Recursion */
  int func(int ind,vector<int>&a,int target,int sum)
   {
       if(ind==0 && sum==target) return 1;
       if(ind<=0) return 0;
       int pos=func(ind-1,a,target,sum+a[ind-1]);
       int neg=func(ind-1,a,target,sum-a[ind-1]);
       return pos+neg;
       
   }
   
    int findTargetSumWays(vector<int>&a ,int target) {
        //Your code here
        int ind=a.size();
        int sum=0;
        return func(ind,a,target,0);
    }

/* DP */
    
 int findTargetSumWays(vector<int>&a ,int target) {
        //Your code here
        int ind=a.size();
        int sum=0;
        vector<vector<int>>dp(ind,vector<int>(target+1,-1));
        return func(ind,a,target,0,dp);
    }
int func(int ind,vector<int>&a,int target,int sum,vector<vector<int>>&dp)
   {
       if(ind==0 && sum==target) return 1;
       if(ind<=0) return 0;
       if(dp[ind][sum]!=-1) return dp[ind][sum];
       int pos=func(ind-1,a,target,sum+a[ind-1],dp);
       int neg=func(ind-1,a,target,sum-a[ind-1],dp);
       return dp[ind][sum]=pos+neg;
       
   }

