// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    vector<string> ans;
    void solve(int i,int j,vector<vector<int>> &m,int n,string cur){
        if(i<0 || i>=n || j<0 || j>=n || m[i][j]==0)
            return ;
        if(i==n-1 && j==n-1){
            ans.push_back(cur);
            cur="";
            return ;
        }
        m[i][j]=0;
        solve(i+1,j,m,n,cur+"D");
        solve(i-1,j,m,n,cur+"U");
        solve(i,j-1,m,n,cur+"L");
        solve(i,j+1,m,n,cur+"R");
        m[i][j]=1;
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        if(m[0][0]==0 || m[n-1][n-1]==0)
            return {};
        string s="";
        solve(0,0,m,n,s);
        return ans;
    }
    
};

    


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends