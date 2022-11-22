/*
  Problem Statement: You are given an N x M binary matrix grid, where 0 represents a sea cell
 and 1 represents a land cell. A move consists of walking from one land cell to another adjacent 
 (4-directionally) land cell or walking off the boundary of the grid. Find the number of land cells
  in the grid for which we cannot walk off the boundary of the grid in any number of moves.
*/

#include<bits/stdc++.h>
using namespace std;

// so we have to find no of land (1) cover by water (0)
// so just find boundary 1 and its connected 1 , becz they never can be the land;

class Solution {

  public:
    int BFSfindEnclaves(vector<vector<int>> &g){
       
       int n=g.size();
       int m=g[0].size();
       int vis[n][m]={0};
       queue<pair<int,int>> q;

       // finding boundary element land (1)
       for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(i==0 || j==0 || j==m-1 || i==n-1){
                if(g[i][j]==1)
                    vis[i][j]=1;
                    q.push({i,j});
            }
        }
       }
     int drow[4]={-1,0,1,0};
     int dcol[4]={0,1,0,-1};

    while(!q.empty()){
            int r= q.front().first;
            int c=q.front().second;
            q.pop();
          for(int i=0;i<4;i++){
              int newRow=i+r;
              int newCol=i+c;
               
             if(newRow>=0 && newRow <n && newCol<m && newCol>=0 && g[newRow][newCol]==1 && vis[newRow][newCol]==0){
                    vis[newRow][newCol]=1;
                    q.push({newRow,newCol});
             }

          }           
    }
    
    int ans=0;
    // land will be that one which are not visited and g[i][j]=1
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(vis[i][j]==0 && g[i][j]==1)
               ans++;
        }
    }
    return ans;
 }


};

int main() {
    
    vector<vector<int>> grid{
        {0, 0, 0, 0},
        {1, 0, 1, 0},
        {0, 1, 1, 0},
        {0, 0, 0, 0}};
        
    Solution obj;
    cout << obj.BFSfindEnclaves(grid) << endl;

}
