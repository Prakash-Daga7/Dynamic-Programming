/*  Link :- https://www.codingninjas.com/codestudio/problems/maximum-sum-of-non-adjacent-elements_843261 */

/***** RECURSION ***********/

#include <bits/stdc++.h> 
int f(int ind , vector<int> &nums)
{
  if(ind==0) return nums[ind];
    if(ind<0) return 0;
    int pick = nums[ind]+f(ind-2,nums);
    int not_pick= 0+f(ind-1,nums);
    return  max(pick,not_pick);
}

int maximumNonAdjacentSum(vector<int> &nums){
    // Write your code here.
    int n=nums.size();
    return f(n-1,nums);
    
}





/****************** DP  *************/

#include <bits/stdc++.h> 
int f(int ind , vector<int> &nums,vector<int> &dp)
{
  if(ind==0) return nums[ind];
    if(ind<0) return 0;
    if(dp[ind]!=-1) return dp[ind];
    int pick = nums[ind]+f(ind-2,nums,dp);
    int not_pick= 0+f(ind-1,nums,dp);
    return dp[ind]= max(pick,not_pick);
}

int maximumNonAdjacentSum(vector<int> &nums){
    // Write your code here.
    int n=nums.size();
    vector<int>dp(n+1,-1);
    return f(n-1,nums,dp);
    
}


/**********  TABULAR *************/

int maximumNonAdjacentSum(vector<int> &nums){
    // Write your code here.
    int n=nums.size();
    vector<int>dp(n+1);
    dp[0]=0;
    int negative=0;
    for(int i=1;i<n;i++)
    {
        int take=nums[i];
        if(i>1) take+= dp[i-2];
        int nontake=0+dp[i-1];
        
        dp[i]=max(take,nontake);
}
    return dp[n];
    
}