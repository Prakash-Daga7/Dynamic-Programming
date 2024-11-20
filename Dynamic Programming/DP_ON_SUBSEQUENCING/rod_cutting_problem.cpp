/* Dp */
class Solution{
  public:
  int f(int ind,int n,int price[],vector<vector<int>>&dp)
  {
      if (ind==0)
      {
          return n*price[0];
      }
      if(dp[ind][n]!=-1)return dp[ind][n];
      int nottake=0+f(ind-1,n,price,dp);
      int take=INT_MIN;
      
      int roadlength=ind+1;
      if(roadlength<=n) take=price[ind]+f(ind,n-roadlength,price,dp);
      return dp[ind][n]=max(take,nottake);
  }
    int cutRod(int price[], int n) {
        //code here
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
       return f(n-1,n,price,dp);
        
    }
};
