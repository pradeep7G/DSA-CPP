// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	void dfs(vector<int> adj[],vector<bool> &vis,stack<int> &s,int u){
	    vis[u]=true;
	    for(auto v:adj[u]){
	        if(vis[v]==false){
	            dfs(adj,vis,s,v);
	        }
	    }
	    s.push(u);
	}
	
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    //dfs
	    /*
    	    vector<bool> vis(V,false);
    	    stack<int> s;
    	    for(int i=0;i<V;i++){
    	        if(vis[i]==false){
    	            dfs(adj,vis,s,i);
    	        }
    	    }
    	    vector<int> res;
    	    while(!s.empty()){
    	        res.push_back(s.top());
    	        s.pop();
    	    }
    	    return res;
	    */
	    //BFS
	    vector<int> indegree(V,0);
	    for(int i=0;i<V;i++){
	        for(auto v:adj[i]){
	            indegree[v]++;
	        }
	    }
	    queue<int> q;
	    for(int i=0;i<V;i++){
	        if(indegree[i]==0)
	            q.push(i);
	    }
	    int count=0;// to count processed nodes and check if there is a cycle or not
	    vector<int> res;
	    while(!q.empty()){
	        int top=q.front();
	        q.pop();
	        res.push_back(top);
	        for(auto v:adj[top]){
	            indegree[v]--;
	            if(indegree[v]==0)
	            q.push(v);
	        }
	        count++;
	    }
	    if(count!=V)
	     return {-1};// there is a cycle
	     return res;
	     
	}
};

// { Driver Code Starts.

/*  Function to check if elements returned by user
*   contains the elements in topological sorted form
*   V: number of vertices
*   *res: array containing elements in topological sorted form
*   adj[]: graph input
*/
int check(int V, vector <int> &res, vector<int> adj[]) {
    
    if(V!=res.size())
    return 0;
    
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
        }
        
        Solution obj;
        vector <int> res = obj.topoSort(N, adj);

        cout << check(N, res, adj) << endl;
    }
    
    return 0;
}  // } Driver Code Ends