// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int maximumSumRectangle(int R, int C, vector<vector<int>> M) {
        int n=M.size();
        int m=M[0].size();
        vector<vector<int>> prefix(n,vector<int>(m,0));
        int ans=INT_MIN;
        for(int i=0;i<n;i++){
            prefix[i][0]=M[i][0];
            ans=max(ans,prefix[i][0]);
        }
        for(int i=0;i<n;i++){
            for(int j=1;j<m;j++){
                prefix[i][j]=M[i][j]+prefix[i][j-1];
                ans=max(ans,prefix[i][j]);
            }
        }
        for(int left=0;left<m;left++){
            for(int right=left;right<m;right++){
               int sum=0;
               for(int k=0;k<n;k++){
                   int curval;
                   if(left==0){
                       curval=prefix[k][right];
                   }
                   else{
                       curval=prefix[k][right]-prefix[k][left-1];
                   }
                   
                   sum=sum+curval;
                   ans=max(ans,sum);
                   if(sum < 0){
                       sum=0;
                   }
               }
            }
        }
        return ans;
    }
};


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) cin >> v[i][j];
        Solution ob;
        cout << ob.maximumSumRectangle(N, M, v) << "\n";
    }
}  // } Driver Code Ends