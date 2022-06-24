// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX 1000


 // } Driver Code Ends
/*You are required to complete this method*/

class Solution{
  public:
        int getMaxHistArea(int v[],int n){
            stack<int> s;
            vector<int> leftsmaller(n,-1),rightsmaller(n,n);
            s.push(-1);
            for(int i=0;i<n;i++){
                while(!s.empty() && s.top()!=-1 && v[s.top()]>v[i]){
                    rightsmaller[s.top()]=i;
                    s.pop();
                }
                if(i>0 && v[i]==v[i-1]){
                    leftsmaller[i]=leftsmaller[i-1];
                }
                else{
                    leftsmaller[i]=s.top();
                }
                s.push(i);
            }
            int ans=0;
            for(int i=0;i<n;i++){
                ans=max(v[i]*(rightsmaller[i]-leftsmaller[i]-1),ans);
            }
            return ans;
        }
        int maxArea(int M[MAX][MAX], int n, int m) {
            int res=0;
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    if(i-1>=0 && M[i][j]){
                        M[i][j]=M[i-1][j]+M[i][j];
                    }
                }
                res=max(res,getMaxHistArea(M[i],m));
            }
            return res;
    }
};


// { Driver Code Starts.
int main() {
    int T;
    cin >> T;

    int M[MAX][MAX];

    while (T--) {
        int n, m;
        cin >> n >> m;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> M[i][j];
            }
        }
        Solution obj;
        cout << obj.maxArea(M, n, m) << endl;
    }
}
  // } Driver Code Ends