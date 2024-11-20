
/*
   https://practice.geeksforgeeks.org/problems/jump-game/1
*/
/* greedy */
 int canReach(int arr[], int n) {
        // code here
        int reach=0;
        for(int i=0;i<n;i++)
        {
            if(i>reach) return 0;
           reach=max(reach,i+arr[i]);
        }
        return 1;
    }
/* Recursion */
 bool f(int i,vector<int>&arr)
  {
      if(i==arr.size()-1) return true;
      int reachable=i+arr[i];

     for(int k=i+1;k<=reachable;k++)
     {
         if(f(k,arr)) return true;
     }
      return false;
  }

    bool canJump(vector<int>& arr) {
        return f(0,arr);
    }

/* Tabular */
    bool canJump(vector<int>& arr) {
            int n=arr.size();
            vector<bool> dp(n,false);
            dp[n-1]=true;
            for(int i=n-2;i>=0;i--)
            {
                int reachable=i+arr[i];
                for(int k=i+1;k<=reachable;k++)
                {
                    if(dp[k]) {dp[i]=true;break;}
                }
            }
            return dp[0];
        }