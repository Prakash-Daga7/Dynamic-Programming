
/* https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/*/


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini=prices[0];
        int maxprofit=0;
         int n=prices.size();
         int cost=0;
         int maxcost=0;
        for(int i=1;i<n;i++)
        {  
           cost=prices[i]-mini;
           if(prices[i]<mini) mini=prices[i];
           if(cost>maxprofit) maxprofit=cost;
        }
        return maxprofit;
    }
};