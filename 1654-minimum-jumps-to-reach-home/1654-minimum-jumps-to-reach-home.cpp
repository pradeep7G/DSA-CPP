class Solution {
public:
    int solve(vector<int> &forb,int a,int b,int x){
        unordered_map<int,int> mp;
        for(int i=0;i<forb.size();i++)
            mp[forb[i]]++;
        //since, min. possible steps, BFS!!
        //visited[0][i] means the ith cell was reached from it's left hand side jumping forward;
        //visited[0][j] means the jth cell was reached from it's right hand side jumping backward;
        
        vector<vector<int>> vis(2,vector<int>(6000,0));
        vis[0][0]=1;
        vis[1][0]=1;
        queue<pair<int,bool>> q;
        q.push({0,false});
        int ans=0;
        while(!q.empty()){
            int size=q.size();
            for(int i=0;i<size;i++){
                auto front=q.front();
                q.pop();
                int idx=front.first;
                if(idx==x)
                    return ans;
                bool flag=front.second;
                int forward=idx+a;
                int backward=idx-b;;
                if(forward<6000 && vis[0][forward]==0 && !mp.count(forward)){
                    vis[0][forward]=1;
                    q.push({forward,false});
                }
                if(backward>=0 and vis[1][backward]==0 and not mp.count(backward) and not flag){
                    vis[1][backward]=1;
                    q.push({backward,true});
                }
            }
            ans++;
        }
        return -1;
    }
    int minimumJumps(vector<int>& forbidden, int a, int b, int x) {
        return solve(forbidden,a,b,x);
        unordered_map<int,int> mp;
        for(int i=0;i<forbidden.size();i++)
            mp[forbidden[i]]++;
        //since we need to find minimum possible steps, bfs!!
        // visited[0][i] means the ith cell was reached from its left hand side jumping forward, 
		// visited[1][i] means the ith cell was reached from its right hand side jumping backward. 
        vector<vector<int>> vis(2,vector<int>(6000,0));
        vis[0][0]=1;
        vis[1][0]=1;
        queue<pair<int,bool>> q;
        q.push({0,false});
        int ans=0;
        while(!q.empty()){
            int size=q.size();
            for(int i=0;i<size;i++){
                auto front=q.front();
                q.pop();
                int index=front.first;
                if(index==x)
                    return ans;
                bool flag=front.second;
                int forward=index+a;
                int backward=index-b;
                if(forward<6000 && vis[0][forward]==0 && !mp.count(forward)){
                    vis[0][forward]=1;
                    q.push({forward,false});
                }
                if(backward>=0 && vis[1][backward]==0 && !mp.count(backward) && !flag){
                    vis[1][backward]=1;
                    q.push({backward,true});
                }
            }
            ans++;
        }
        return -1;
    }
};