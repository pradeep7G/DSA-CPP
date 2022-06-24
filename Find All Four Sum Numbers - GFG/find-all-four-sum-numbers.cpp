// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    // arr[] : int input array of integers
    // k : the quadruple sum required
    vector<vector<int> > fourSum(vector<int> &arr, int k) {
        // set<vector<int>> s;
        // sort(begin(arr),end(arr));
        // int n=arr.size();
        // for(int i=0;i<n-3;i++)
        // {
        //     for(int j=i+1;j<n-2;j++)
        //     {
        //         int start=j+1,end=n-1;
        //         while(start<end){
        //             int sum=arr[i]+arr[j]+arr[start]+arr[end];
        //             if(sum==k){
        //                 s.insert({arr[i],arr[j],arr[start],arr[end]});
        //                 start++;
        //                 end--;
        //             }
        //             else if(sum>k){
        //                 end--;
        //             }
        //             else{
        //                 start++;
        //             }
        //         }
        //     }
        // }
        // vector<vector<int>> ans;
        // for(auto v:s){
        //     ans.push_back(v);
        // }
        // return ans;
        set<vector<int>> s;
        sort(begin(arr),end(arr));
        int n=arr.size();
        for(int i=0;i<n-3;i++){
            for(int j=i+1;j<n-2;j++){
                int start=j+1,end=n-1;
                while(start<end){
                    int sum=arr[i]+arr[j]+arr[start]+arr[end];
                    if(sum==k){
                        s.insert({arr[i],arr[j],arr[start],arr[end]});
                        start++,end--;
                    }
                    else if(sum<k){
                        start++;
                    }
                    else
                    {
                        end--;
                    }
                }
            }
        }
        vector<vector<int>> ans;
        for(auto it:s)
        ans.push_back(it);
        return ans;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, i;
        cin >> n >> k;
        vector<int> a(n);
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        vector<vector<int> > ans = ob.fourSum(a, k);
        for (auto &v : ans) {
            for (int &u : v) {
                cout << u << " ";
            }
            cout << "$";
        }
        if (ans.empty()) {
            cout << -1;
        }
        cout << "\n";
    }
    return 0;
}  // } Driver Code Ends