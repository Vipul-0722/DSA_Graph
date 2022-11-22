
#include<bits/stdc++.h>
using namespace std;

class Solution {

private:
  void DFS(int r,int c,vector<vector<int>> &g, vector<vector<int>> &vis, int drow[], int dcol[]){
    
    vis[r][c]=1;
    int n=g.size();
    int m=g[0].size();

    for(int i=0;i<4;i++){

     int nrow=i+drow[i];
     int ncol=i+dcol[i];

      if(nrow >=0 && nrow <n && ncol >= 0 && ncol < m 
            && !vis[nrow][ncol] && g[nrow][ncol] == 0) {
                DFS(nrow, ncol, vis, g, drow, dcol); 
            }

    }

  }

public:
int DFSfindEnclaves(vector<vector<int>> &g){
       int n=g.size();
       int m=g[0].size();
 
       vector<vector<int>> vis(n, vector<int>(m,0)); 
   
       int drow[4]={-1,0,1,0};
       int dcol[4]={0,1,0,-1};

      // 1st row

       for(int i=0;i<n;i++){
          if(g[0][i]==1 && vis[0][i]==0)
              DFS(0,i,g,vis,drow,dcol);  
       }

       // 1st Column

       for(int i=0;i<n;i++){
          if(g[i][0]==1 && vis[i][0]==0)
              DFS(i,0,g,vis,drow,dcol);
       }

       // last row
       for(int i=0;i<n;i++){
          if(g[n-1][i]==1 && vis[n-1][i]==0)
              DFS(n-1,i,g,vis,drow,dcol);
       }

       // last col

       for(int i=0;i<n;i++){
          if(g[i][m-1]==1 && vis[i][m-1]==0)
              DFS(i,m-1,g,vis,drow,dcol);
       }


       int ans=0;
       for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(g[i][j]==1 && !vis[i][j]){
                ans++;
            }
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
    cout << obj.DFSfindEnclaves(grid) << endl;

}


