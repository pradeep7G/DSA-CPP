class Solution {
public:
    void solve(int ind,int target,vector<vector<int>> &g,vector<int> &path,vector<vector<int>> &res){
        if(ind==target){
            res.push_back(path);
            return ;
        }
        for(auto child:g[ind]){
            // cout<<child<<"\n";
            path.push_back(child);
            solve(child,target,g,path,res);
            path.pop_back();
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<vector<int>> g(n);
        for(int i=0;i<n;i++){
            for(auto j:graph[i]){
                g[i].push_back(j);
            }
        }
        vector<vector<int>> res;
        vector<int> path;
        path.push_back(0);
        solve(0,n-1,g,path,res);
        return res;
    }
};