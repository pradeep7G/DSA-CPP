class Solution {
public:
    bool bipartite(vector<vector<int>> &graph,int src,vector<int> &colors){
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
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> colors(n,0);
        for(int i=0;i<n;i++){
            if(colors[i])
                continue;
            if(bipartite(graph,i,colors))
                return false;
        }
        return true;
    }
};