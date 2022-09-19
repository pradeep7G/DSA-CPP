class Solution {
public:
    bool dfsBrute(vector<vector<int>> &heights,int ocean,int i,int j,vector<vector<bool>> &vis,vector<vector<bool>> &pa){
        //base case:
        if(ocean==1 && (i==0 || j==0)){
            return true;
        }
        else if(ocean==2 && (i==heights.size()-1 || j==heights[0].size()-1)){
            return true;
        }
        vis[i][j]=true;
        if(pa[i][j])
            return true;
        if(i-1>=0 && !vis[i-1][j] && heights[i-1][j]<=heights[i][j]){
            if(dfsBrute(heights,ocean,i-1,j,vis,pa))
                return true;
        }
        if(i+1<heights.size() && !vis[i+1][j] && heights[i+1][j]<=heights[i][j]){
            if(dfsBrute(heights,ocean,i+1,j,vis,pa))
                return true;
        }
        if(j-1>=0 && !vis[i][j-1] && heights[i][j-1]<=heights[i][j]){
            if(dfsBrute(heights,ocean,i,j-1,vis,pa))
                return true;
        }
        if(j+1<heights[0].size() && !vis[i][j+1] && heights[i][j+1]<=heights[i][j])
        {
            if(dfsBrute(heights,ocean,i,j+1,vis,pa))
                return true;
        }
        return false;
    }
    vector<vector<int>> Bruteforce(vector<vector<int>>& heights){
         //TLE!!
        int m=heights.size(),n=heights[0].size();
        vector<vector<bool>> pa(m,vector<bool>(n,false));
        vector<vector<int>> res;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                //try for each cell, check if we reach pacific and also check again if we reach atlantic
                vector<vector<bool>> vis1(m,vector<bool>(n,false));
                if(dfsBrute(heights,1,i,j,vis1,pa)){
                    vector<vector<bool>> vis2(m,vector<bool>(n,false));
                    if(dfsBrute(heights,2,i,j,vis2,pa)){
                        pa[i][j]=true;
                        res.push_back({i,j});
                    }
                }
            }
        }
        return res;
    }
    int dirs[5]={1,0,-1,0,1};
    void dfs(vector<vector<int>> &heights,vector<vector<bool>> &vis,int h,int i,int j){
        int m=heights.size(),n=heights[0].size();
        if(i<0 || j<0 || i>=m || j>=n || vis[i][j] || heights[i][j]<h)
            return ;
        vis[i][j]=true;
        for(int dir=0;dir<4;dir++){
            dfs(heights,vis,heights[i][j],i+dirs[dir],j+dirs[dir+1]);
        }
        return ;
    }
    // void dfs(vector<vector<int>> &heights,vector<vector<bool>> &vis,int h,int i,int j){
    //     int m=heights.size(),n=heights[0].size();
    //     if(i<0 || j<0 || i>=m || j>=n || vis[i][j] || heights[i][j]<h)
    //         return ;
    //     vis[i][j]=true;
    //     for(int x=0;x<4;x++){
    //         dfs(heights,vis,heights[i][j],i+dirs[x],j+dirs[x+1]);
    //     }
    //     return ;
    // }
    void bfs(queue<pair<int,int>> &q,vector<vector<bool>> &vis,vector<vector<int>> &heights){
        int m=heights.size(),n=heights[0].size();
        while(!q.empty()){
            pair<int,int> front=q.front();
            q.pop();
            for(int dir=0;dir<4;dir++){
                int i=front.first + dirs[dir],j=front.second + dirs[dir+1];
                if(i<0 || j<0 || i>=m || j>=n || vis[i][j] || heights[i][j]<heights[front.first][front.second])
                    continue;
                vis[i][j]=true;
                q.push({i,j});
            }
        }
    }
    // void bfs(queue<pair<int,int>> &q,vector<vector<bool>> &vis,vector<vector<int>> &heights){
    //     int m=heights.size(),n=heights[0].size();
    //     while(!q.empty()){
    //         pair<int,int> front=q.front();
    //         q.pop();
    //         for(int i=0;i<4;i++){
    //             int x=front.first + dirs[i],y=front.second + dirs[i+1];
    //             if(x<0 || x>=m || y<0 || y>=n || vis[x][y] || heights[x][y]<heights[front.first][front.second])
    //                 continue;
    //             vis[x][y]=true;
    //             q.push({x,y});
    //         }
    //     }
    // }
    vector<vector<int>> optimised(vector<vector<int>>& heights) {
       //do dfs for pacific border cells and mark visited/reachable nodes  and do the same for atlantic border cells and common reachable cells i.e cell's that are reachable from both oceans
        //Do both bfs and dfs
        int m=heights.size();
        int n=heights[0].size();
        vector<vector<bool>> pacific(m,vector<bool>(n,false));
        vector<vector<bool>> atlantic(m,vector<bool>(n,false));
        vector<vector<int>> res;
        
        for(int i=0;i<m;i++){
            dfs(heights,pacific,INT_MIN,i,0);
            dfs(heights,atlantic,INT_MIN,i,n-1);
        }
        for(int i=0;i<n;i++){
            dfs(heights,pacific,INT_MIN,0,i);
            dfs(heights,atlantic,INT_MIN,m-1,i);
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(pacific[i][j] && atlantic[i][j]){
                    res.push_back({i,j});
                }
            }
        }
       
        // queue<pair<int,int>> pac,atl;
        // for(int i=0;i<n;i++){
        //     pac.push({0,i});
        //     atl.push({m-1,i});
        //     pacific[0][i]=true;
        //     atlantic[m-1][i]=true;
        // }
        // for(int i=0;i<m;i++){
        //     pac.push({i,0});
        //     atl.push({i,n-1});
        //     pacific[i][0]=true;
        //     atlantic[i][n-1]=true;
        // }
        // bfs(pac,pacific,heights);
        // bfs(atl,atlantic,heights);
        // for(int i=0;i<m;i++){
        //     for(int j=0;j<n;j++)
        //     {
        //         if(pacific[i][j] && atlantic[i][j]){
        //             res.push_back({i,j});
        //         }
        //     }
        // }
        return res;
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
       return optimised(heights);
    }
};