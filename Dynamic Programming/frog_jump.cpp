/*
link:- https://www.codingninjas.com/codestudio/problems/frog-jump_3621012
*/

/************************* RECURSION ****************************/
 int func(int ind,vector<int> &heights,vector<int>&dp)
{
 if(ind==0) return 0;
    if(dp[ind]!= -1) return dp[ind];
    int l= (ind-1)+abs(heights[ind]-heights[ind-1]);
    int r=INT_MAX;
    if(ind>1) 
    r= func(ind-2,heights,dp)+abs(heights[ind]-heights[ind-2]);
    return dp[ind]=min(l,r);
        
}

int frogJump(int n, vector<int> &heights)
{
    // Write your code here.
    vector<int> dp(n+1,-1);
    return func(n-1,heights,dp);
}


/****************************** TABULAR ********************/

int frogJump(int n, vector<int> &heights)
{
    // Write your code here.
    vector<int> dp(n,0);
    dp[0]=0;
    for(int i=1;i<n;i++)
    {
        int l=dp[i-1] + abs(heights[i]-heights[i-1]);
        int r= INT_MAX;
        if(i>1)
        { r=dp[i-2]+ abs(heights[i]-heights[i-2]);}
        dp[i]=min(l,r);
    }
    
    return dp[n-1];
  
}