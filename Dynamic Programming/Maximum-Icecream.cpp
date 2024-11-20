/* https://leetcode.com/problems/maximum-ice-cream-bars/ */

/* greedy */
class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        
        sort(costs.begin(),costs.end());
        int count=0;
        for(int i=0;i<costs.size();i++)
        {
            if(costs[i]<=coins)
            {
                coins=coins-costs[i];
                count++;
            }
            else
            {
                break;
            }
        }
        return count;
    }
};


/* Recursion  */


int func(int ind,int target,vector<int>&arr)
   {
       if(ind==0) 
       {
         if(target>=arr[0]) return 1;
         return 0;
       }
        
      // if(ind==0) return arr[0]==target;
       if(ind<0) return 0;

       int nottake=func(ind-1,target,arr);
       int take=0;
       if(target>=arr[ind])
       {
           take=1+func(ind-1,target-arr[ind],arr);
          
       } return max(take,nottake);
   }

    int maxIceCream(vector<int>& costs, int coins) {
         return func(costs.size()-1,coins,costs);
    }


/* Greedy */

  sort(costs.begin(),costs.end());
        int count=0;
        for(int i=0;i<costs.size();i++ )
        {
            
            coins=coins-costs[i];
            if(coins>=0)
            { 
              count++;
             }
            else
            {
               return count;
            }
        }
        return count;