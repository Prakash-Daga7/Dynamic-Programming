/* https://leetcode.com/problems/unique-paths-iii/description/   */




class Solution {
public:
  int f(int i,int j,int c,int empty,vector<vector<int>>& grid)
  {
      if(i<0 || j<0|| i>=grid.size()||j<0 || j>=grid[0].size() || grid[i][j]==-1) return 0;
      
      if(grid[i][j]==2) 
      {if(c==empty) return 1;
         return 0;
      }
    
      grid[i][j]=-1;
      int up=f(i-1,j,c+1,empty,grid);
      int left=f(i,j-1,c+1,empty,grid);
      int down=f(i+1,j,c+1,empty,grid);
      int right=f(i,j+1,c+1,empty,grid);
      grid[i][j]=0;
      return up+left+down+right;
  }
    int uniquePathsIII(vector<vector<int>>& grid) {
        int empty=1;
        int m=grid.size();
        int n=grid[0].size();
        int posii=n,posij=n;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1)
                {
                  posii=i;
                  posij=j;
                 
                }
                if(grid[i][j]==0)
                empty++;
            }

        }
        return f(posii,posij,0,empty,grid);
        
    }
};