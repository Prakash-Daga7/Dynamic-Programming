/*
Link:- https://leetcode.com/problems/min-cost-climbing-stairs/
*/

/*  Recursion */
 int func(vector<int>&cost,int i)
   { 
       if(i>=cost.size()) return 0;
     
      int one=cost[i]+func(cost,i+1);
      int two=cost[i]+func(cost,i+2);
      
      return min(one,two);
   }

    int minCostClimbingStairs(vector<int>& cost) {
        return min(func(cost,0),func(cost,1));
    }

/* Tabular */
int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int> dp(n+1,0);
        dp[0]=cost[0];
        dp[1]=cost[1];
        for(int i=2;i<=n;i++)
        {
            int one=cost[i]+dp[i-1];
            int two=cost[i]+dp[i-2];
            dp[i]=min(one,two);
        }
        return min(dp[n],dp[n-1]);
    }

/* Space Optimized */
int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        int dp1=cost[0];
        int dp2=cost[1];
        for(int i=2;i<=n;i++)
        {
            int one=cost[i]+dp1;
            int two=cost[i]+dp2;
            dp1=dp2;
            dp2=min(one,two);
        }
        return min(dp1,dp2);
    }

/* Greedy */
    for (int i = cost.size() - 3; ~i; i--)
            cost[i] += min(cost[i+1], cost[i+2]);
        return min(cost[0], cost[1]);
