// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int kthLargest(vector<int> &arr,int n,int k){
        priority_queue<int,vector<int>,greater<int>> pq;
        vector<int> pref(n+1);
        pref[0]=0;
        for(int i=0;i<n;i++){
            pref[i+1]=pref[i]+arr[i];
        }
        for(int i=1;i<=n;i++){
            for(int j=i;j<=n;j++){
                long long sum=pref[j]-pref[i-1];
                if(pq.size()<k){
                    pq.push(sum);
                }
                else{
                    if(pq.top()<sum){
                        pq.pop();
                        pq.push(sum);
                    }
                }
            }
        }
        return pq.top();
    }
};

// { Driver Code Starts.

int main(){
    
    int T;
    cin>>T;
    while(T--){
        int N,K;
        cin>>N;
        cin>>K;
        vector<int> Arr(N);
        for(int i=0;i<N;i++){
            cin>>Arr[i];
        }
        Solution ob;
        int ans=ob.kthLargest(Arr,N,K);
        cout<<ans<<endl;
    }
    return 0;
}  // } Driver Code Ends