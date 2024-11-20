/*
  Link:- https://practice.geeksforgeeks.org/problems/path-in-matrix3805/1
*/

class Solution{
public:

  int func(vector<vector<int>>&matrix,int i,int j,int m,int n)
  {
      
      if(j<0|| i<0 || i>m || j>n) return INT_MIN;
      if(i==m) return matrix[i][j];
      return matrix[i][j]+max(func(matrix,i+1,j-1,m,n),max(func(matrix,i+1,j,m,n),func(matrix,i+1,j+1,m,n)));
  }

    int maximumPath(int N, vector<vector<int>> &matrix)
    {
        // code here
        int m=matrix.size();
        int n=matrix[0].size();
        int maxi=INT_MIN;
        for(int j=0;j<n;j++)
        {
            maxi=max(maxi,func(matrix,0,j,m-1,n-1));
        }
        return maxi;
    }
};