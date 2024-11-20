/*
   Link:- https://leetcode.com/problems/house-robber/
*/


/*    RECURSION    */

class Solution {
public:

    int f(int ind,vector<int> &nums)
    {
        if(ind==0) return nums[ind];
        if(ind<0) return 0;
        int take=nums[ind]+f(ind-2,nums);
        int nontake=0+f(ind-1,nums);
        return max(take,nontake);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
       int ans=f(n-1,nums);
         return ans;
    }
};

/*    DP    */

class Solution {
public:

    int f(int ind,vector<int> &nums,vector<int> &dp)
    {
        if(ind==0) return nums[ind];
        if(ind<0) return 0;
        if(dp[ind]!=-1) return dp[ind];
        int take=nums[ind]+f(ind-2,nums,dp);
        int nontake=0+f(ind-1,nums,dp);
        return dp[ind]=max(take,nontake);
    }
    int rob(vector<int>& nums) {

        int n=nums.size();
                vector<int>dp(n+1,-1);
       int ans=f(n-1,nums,dp);
         return ans;
    }
};