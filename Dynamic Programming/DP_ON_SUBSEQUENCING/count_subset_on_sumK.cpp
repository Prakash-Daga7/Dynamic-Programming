/*
https://practice.geeksforgeeks.org/problems/perfect-sum-problem5633/1
*/

// i will try with all possible method give TLE

int perfectSum(int arr[], int n, int sum1)
	{
	    int count=0;
	   
        // Your code goes here
        
        for(int i=0;i<=pow(2,n)-1;i++)
        { int sum=0;
            for(int j=0;j<n;j++)
            {
                if( i & 1<<j)
                {
                    sum=sum+arr[j];
                }
            }
           if(sum==sum1)
           count++;
          
        }
      return count;
	}


/*dp*/
int f(int ind,int sum,int arr[],vector<vector<int>>&dp)
    {
        if(sum==0) return 1;
        
        if(ind==0) return arr[0]==sum;
        if(dp[ind][sum]!=-1) return dp[ind][sum];
        int nottake=f(ind-1,sum,arr,dp);
        int take=0;
        if(arr[ind]<=sum) take=f(ind-1,sum-arr[ind],arr,dp);
        return dp[ind][sum]=take + nottake;
    }
	
	int perfectSum(int arr[], int n, int sum1)
	{
	    vector<vector<int>>dp(n+1,vector<int>(sum1+1,-1));
	   return f(n-1,sum1,arr,dp);
	}
