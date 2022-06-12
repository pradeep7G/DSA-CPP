// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        int tot=0;
        int n=grid.size();
        int m=grid[0].size();
        for(int i=0;i<grid.size();i++)
        for(int j=0;j<grid[0].size();j++){
           tot+=(grid[i][j]!=0);
           if(grid[i][j]==2){
               q.push({i,j});
           }    
        }
        int count=0;
        int day=0;
        vector<vector<int>> dirs{{1,0},{-1,0},{0,1},{0,-1}};
        while(!q.empty()){
            int size=q.size();
            count+=size;
            for(int i=0;i<size;i++)
            {
             auto p=q.front();
             q.pop();
            for(int j=0;j<4;j++){
                int x=p.first+dirs[j][0];
                int y=p.second+dirs[j][1];
                if(x<0 || x>=n | y<0 || y>=m || grid[x][y]==0 || grid[x][y]==2) continue;
                grid[x][y]=2;
                q.push({x,y});
            }
            }
            if(!q.empty()) day++;
        }
        return (count!=tot)? -1 : day;
        
    }
    
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends