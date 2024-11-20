/* https://leetcode.com/problems/jump-game-ii/ */

class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.size()==1) return 0;
        vector<int>dp(nums.size(),-1);
       return func(0,nums,dp);
    }
    
    int count=0;
    int func(int i,vector<int>&nums,vector<int>&dp)
    {int mini=1e9;
        if(i>=nums.size()-1) return 0;
         if(dp[i]!=-1) return dp[i];
        int reachable=i+nums[i];
       
        for(int k=i+1;k<=reachable;k++)
        {
           mini= min(mini,1+func(k,nums,dp));
        }
      return dp[i]=mini;
    }
  
};