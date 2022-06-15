// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    bool isnotpossible(int cur,vector<vector<int>> &g,vector<bool> &vis,vector<bool> &onpath){
        vis[cur]=true;
        onpath[cur]=true;
        for(auto i:g[cur]){
            if(vis[i]==false && isnotpossible(i,g,vis,onpath)==true){
                return true;
            } else{
                if(onpath[i])
                {
                    return true;
                }
            }
        }
        onpath[cur]=false;
        return false;
    }
	bool isPossible(int N, vector<pair<int, int> >& prerequisites) {
	    vector<vector<int>> g(N);
	    for(auto i:prerequisites){
	        g[i.second].push_back(i.first);
	    }
	    vector<bool> vis(N,false);
	    vector<bool> onpath(N,false);
	    for(int i=0;i<N;i++){
	        if(!vis[i] && isnotpossible(i,g,vis,onpath)){
	            return false;
	        }
	    }
	    return true;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
    	int N, P;
        vector<pair<int, int> > prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i) {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
	}
	return 0;
}  // } Driver Code Ends