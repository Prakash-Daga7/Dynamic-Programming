
/*
https://practice.geeksforgeeks.org/problems/kadanes-algorithm-1587115620/1
*/


/* Brute Force (O(n^3)))*/ 
 long long maxSubarraySum(int arr[], int n){
        
        // Your code here
        long long int maxi=INT_MIN;
        for(int i=0;i<n-1;i++)
        {
            for(int j=i;j<n;j++)
            {
               long long int sum=0;
                for(int k=i;k<=j;k++)
                {
                    sum+=arr[k];
                   
                } maxi=max(maxi,sum);
            }
        }
        return maxi;
        
    }


/* optimize (O(n^2))*/
    long long maxSubarraySum(int arr[], int n){
            
            // Your code here
            long long int maxi=INT_MIN;
            for(int i=0;i<n-1;i++)
            {
                long long int sum=0;
                for(int j=i;j<n;j++)
                {
                    sum+=arr[j];
                    maxi=max(maxi,sum);
                }
            }
            return maxi;
            
        }

/* kadane's (O(n))*/
   long long maxSubarraySum(int arr[], int n){
        
        // Your code here
       int sum=0;
       int maxi=arr[0];
       for(int i=0;i<n;i++)
    {
        sum=sum+arr[i]; 
        if(sum>maxi) maxi=sum;
        if(sum<0) sum=0; 
    }
    return maxi;
   }