// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int minSubset(vector<int> &arr,int n){
        sort(arr.begin(),arr.end());
        reverse(arr.begin(),arr.end());
        long long sum=accumulate(arr.begin(),arr.end(),0LL);
        long long presum=0;
        for(int i=0;i<n;i++){
            presum+=arr[i];
            if(presum>sum-presum){
                return i+1;
            }
        }
        return n;
    }
};

// { Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<int> Arr(N);
        for(int i=0;i<N;i++){
            cin>>Arr[i];
        }
        Solution ob;
        cout<<ob.minSubset(Arr,N)<<endl;
    }
    return 0;
}  // } Driver Code Ends