class Solution {
public:

    int solve(vector<vector<int>> &grid){
        int total=0;
        int m=grid.size(),n=grid[0].size();
        queue<pair<int,int>> q;
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++){
                total += (grid[i][j]!=0);
                if(grid[i][j]==2)
                    q.push({i,j});
            }
        int count=0,days=0;
        int dirs[5]={-1,0,1,0,-1};
        while(!q.empty()){
            int sz=q.size();
            count += sz;
            for(int i=0;i<sz;i++){
                auto top=q.front();
                q.pop();
                int x=top.first,y=top.second;
                grid[x][y]=0;
                for(int dir=0;dir<4;dir++){
                    int xDir=x+dirs[dir],yDir=y+dirs[dir+1];
                    if(xDir<0 || yDir<0 || xDir>=m || yDir>=n || grid[xDir][yDir]!=1)
                        continue;
                    grid[xDir][yDir]=2;
                    q.push({xDir,yDir});
                }
            }
            if(!q.empty())
            days += 1;
        }
        return total == count ? days : -1;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        //BFS queue
        return solve(grid);
        int rotten=0;
        int m=grid.size(),n=grid[0].size();
        queue<pair<int,int>> q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                rotten+=(grid[i][j]!=0);
                if(grid[i][j]==2){
                    q.push({i,j});
                }
            }
        }
        int count=0;
        int days=0;
        int dirs[4][2]={{0,-1},{0,1},{1,0},{-1,0}};
        while(!q.empty()){
            count+=q.size();
            int size=q.size();
            for(int i=0;i<size;i++){
                auto top=q.front();
                q.pop();
                int x=top.first,y=top.second;
                grid[x][y]=0;
                for(int dir=0;dir<4;dir++){
                    int x_dir=x+dirs[dir][0];
                    int y_dir=y+dirs[dir][1];
                    if(x_dir<0 || y_dir<0 || y_dir>=n || x_dir>=m || grid[x_dir][y_dir]!=1){
                        continue;
                    }
                    grid[x_dir][y_dir]=2;
                    q.push({x_dir,y_dir});
                }
            }
            if(!q.empty())
                days++;
        }
        return rotten==count?days:-1;
    }
};