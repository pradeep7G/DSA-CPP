class Solution {
public:
    bool dfs(int i,vector<vector<int>> &graph,vector<bool> &vis,vector<bool> &outStack){
        vis[i]=true;
        outStack[i]=true;
        for(auto j:graph[i]){
            if(!vis[j]){
                if(dfs(j,graph,vis,outStack)){
                    return true;
                }
            }
            else if(outStack[j]){
                return true;
            }
        }
        outStack[i]=false;
        return false;
    }
    bool canFinish(int n, vector<vector<int>>& pre) {
        //find if there is a cycle in directed graph
        vector<vector<int>> graph(n);
        for(int i=0;i<pre.size();i++){
            graph[pre[i][1]].push_back(pre[i][0]);
        }
        vector<bool> vis(n,false);
        vector<bool> outstack(n,false);
        for(int i=0;i<n;i++){
            if(dfs(i,graph,vis,outstack)){
                return false;
            }
        }
        return true;
    }
};