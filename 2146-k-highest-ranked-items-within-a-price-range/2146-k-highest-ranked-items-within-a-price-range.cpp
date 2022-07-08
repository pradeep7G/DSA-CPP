class Solution {
public:
    struct compare {
        bool operator()(vector<int> &a,vector<int> &b){
            if(a[0]==b[0]){
                if(a[1]==b[1]){
                    if(a[2]==b[2]){
                        return a[3]>b[3];
                    }
                    else{
                        return a[2]>b[2];
                    }
                }
                return a[1]>b[1];
            }
            return a[0]>b[0];
        }
    };
    vector<vector<int>> highestRankedKItems(vector<vector<int>>& grid, vector<int>& pricing, vector<int>& start, int k) {
        //bfs + priority_queue
        if(grid[start[0]][start[1]]==0)
            return {{}};
        int m=grid.size(),n=grid[0].size();
        vector<vector<int>> vis(m,vector<int>(n,false));
        vector<vector<int>> res;
        vis[start[0]][start[1]]=true;
        priority_queue<vector<int>,vector<vector<int>>,compare> pq;
        queue<pair<int,int>> q;
        q.push({start[0],start[1]});
        int dirs[5]={1,0,-1,0,1};
        int distance=0;
        while(!q.empty()){
            int size=q.size();
            for(int item=0;item<size;item++)
            {
                 auto front=q.front();
                 q.pop();
                 int val=grid[front.first][front.second];
                 if(val!=1 && val!=0)
                 {
                    if(val>=pricing[0] && val<=pricing[1])
                        pq.push({distance,val,front.first,front.second});
                 }
                for(int i=0;i<4;i++)
                {
                    int x=front.first + dirs[i],y=front.second + dirs[i+1];
                    if(x<0 || y<0 || x>=m || y>=n || grid[x][y]==0 || vis[x][y])
                        continue;
                    vis[x][y]=true;
                    q.push({x,y});
                }   
            }
            distance++;
        }
        while(k-- && !pq.empty()){
            auto top=pq.top();
            pq.pop();
            res.push_back({top[2],top[3]});
        }
        return res;
    }
};