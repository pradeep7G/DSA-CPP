class Solution {
public:
    bool bipartiteBFS(vector<vector<int>> &graph,int src,vector<int> &colors){
        queue<int> q;
        q.push(src);
        colors[src]=1;
        while(!q.empty()){
            int i=q.front();
            q.pop();
            for(auto j:graph[i]){
                if(!colors[j]){
                    colors[j]=-colors[i];
                    q.push(j);
                }
                else if(colors[j]==colors[i]){
                        return true;
                }
            }
        }
        return false;
    }
    bool bipartiteDFS(vector<vector<int>> &graph,int i,vector<int> &colors,vector<bool> &vis,int parentColor){
        vis[i]=true;
        for(auto j:graph[i]){
            if(!vis[j]){
                // if(!colors[j]){
                    colors[j]=-parentColor;
                // }
                // else if(colors[j]==colors[i]){
                //     return true;
                // }
                if(bipartiteDFS(graph,j,colors,vis,colors[j]))
                    return true;
            }
            else if(colors[j]==colors[i]){
                    return true;
            }
        }
        return false;
    }
    bool isBipartiteDfs(vector<vector<int>> &graph){
        int n=graph.size();
        vector<int> colors(n,0);
        vector<bool> vis(n,false);
        for(int i=0;i<n;i++){
            if(colors[i])
                continue;
            colors[i]=1;
            if(bipartiteDFS(graph,i,colors,vis,colors[i]))
                return false;
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        return isBipartiteDfs(graph);
        int n=graph.size();
        vector<int> colors(n,0);
        for(int i=0;i<n;i++){
            if(colors[i])
                continue;
            if(bipartiteBFS(graph,i,colors))
                return false;
        }
        return true;
    }
};