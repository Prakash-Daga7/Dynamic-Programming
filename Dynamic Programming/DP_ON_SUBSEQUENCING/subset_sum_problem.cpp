/*
  Link:-https://practice.geek sforgeeks.org/problems/subset-sum-problem-1611555638/1
*/

/* Recursion */

class Solution{   
public:
  bool func(int ind,int target,vector<int>&arr)
  {
      if(target==0) return true;
      if(ind==0) return (arr[0]==target);
      
      bool not_take=func(ind-1,target,arr);
      bool take=false;
      if(target>=arr[ind]) 
      {
          take=func(ind-1,target-arr[ind],arr);
      }
     return take||not_take;
  }
  
  
    bool isSubsetSum(vector<int>arr, int sum){
        // code here 
      return func(arr.size()-1,sum,arr);
    }
};

/* dp */
class Solution{   
public:
  bool func(int ind,int target,vector<int>&arr, vector<vector<int>>&dp)
  {
      if(target==0) return true;
      if(ind==0) return (arr[0]==target);
      if(dp[ind][target]!= -1) return dp[ind][target];
      bool not_take=func(ind-1,target,arr,dp);
      bool take=false;
      if(target>=arr[ind]) 
      {
          take=func(ind-1,target-arr[ind],arr,dp);
      }
     return dp[ind][target]=take||not_take;
  }
  
  
    bool isSubsetSum(vector<int>arr, int sum){
        // code here 
        vector<vector<int>>dp(arr.size(),vector<int>(sum+1,-1));
      return func(arr.size()-1,sum,arr,dp);
    }
};


/* dp tabular (bug)*/
 bool isSubsetSum(vector<int>arr, int sum){
        // code here 
        int n=arr.size();
        vector<vector<int>>dp(arr.size(),vector<int>(sum+1,0));
      for(int i=0;i<n;i++) dp[i][0]=true;
      dp[0][arr[0]]=true;
      
      for(int ind=1;ind<n;ind++)
      {
          for(int target=1;target<=sum;target++)
          {
               bool not_take=dp[ind-1][target];
               bool take=false;
               if(target>=arr[ind]) 
                {
                   take=dp[ind-1][target-arr[ind]];
           
                 }
                return dp[ind][target]=take|not_take;
              
          }
      }
      return dp[n-1][sum];
    }