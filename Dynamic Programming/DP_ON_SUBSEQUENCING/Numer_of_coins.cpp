/*
 Link:- https://practice.geeksforgeeks.org/problems/number-of-coins1824/1
*/


/* recursion */
class Solution{

	public:
	int f(int ind,int target,int coins[] )
	{
	    if(ind==0){
	        if(target %coins[0]==0) return target/coins[0];
	        return 1e9;
	    }
	    int nottake=0+f(ind-1,target,coins);
	    int take=INT_MAX;
	    if(coins[ind]<=target) take=1+f(ind,target-coins[ind],coins);
	    return min(take,nottake);
	}
	int minCoins(int coins[], int m, int target) 
	{ 
	    // Your code goes here
	  
	   int ans=f(m-1,target,coins);
	     if(ans>=1e9) return -1;
	     return ans;	} 
	  
};



/* dp */
	public:
	int f(int ind,int target,int coins[],vector<vector<int>>&dp )
	{
	    if(ind==0){
	        if(target %coins[0]==0) return target/coins[0];
	        return 1e9;
	    }
	    if(dp[ind][target]!=-1) return dp[ind][target];
	    int nottake=0+f(ind-1,target,coins,dp);
	    int take=INT_MAX;
	    if(coins[ind]<=target) take=1+f(ind,target-coins[ind],coins,dp);
	    return dp[ind][target]=min(take,nottake);
	}
	int minCoins(int coins[], int m, int target) 
	{ 
	    // Your code goes here
	  vector<vector<int>>dp(m,vector<int>(target+1,-1));
	   int ans=f(m-1,target,coins,dp);
	     if(ans>=1e9) return -1;
	     return ans

    }
};

/* Tabular */
class Solution{
    public:
    int minCoins(int coins[], int m, int target) 
    { 
        // Your code goes here
        vector<vector<int>>dp(m,vector<int>(target+1,1e9));
        for(int i=0;i<m;i++) dp[i][0]=0;
        for(int i=0;i<=target;i++) if(i%coins[0]==0) dp[0][i]=i/coins[0];
        for(int i=1;i<m;i++)
        {
            for(int j=1;j<=target;j++)
            {
                int nottake=dp[i-1][j];
                int take=1e9;
                if(coins[i]<=j) take=1+dp[i][j-coins[i]];
                dp[i][j]=min(take,nottake);
            }
        }
        if(dp[m-1][target]>=1e9) return -1;
        return dp[m-1][target];
    } 
      
};