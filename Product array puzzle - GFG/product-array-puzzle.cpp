// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;



 // } Driver Code Ends
//User function template for C++

class Solution{
  public:
    // nums: given vector
    // return the Product vector P that hold product except self at each index
    typedef long long ll;
    vector<long long int> productExceptSelf(vector<long long int>& nums, int n) {
        // vector<long long int> pref(n+1,1);
        // for(int i=0;i<n;i++){
        //     pref[i+1]=pref[i]*nums[i];
        // }
        // vector<long long int> suf(n+1,1);
        // for(int i=n;i>0;i--)
        // {
        //     suf[i-1]=nums[i-1]*suf[i];
        // }
        // vector<long long int> ans(n,0);
        // for(int i=1;i<=n;i++)
        // {
        //     ans[i-1]=suf[i]*pref[i-1];
        // }
        // return ans;
        vector<ll> pref(n+1,1);
        vector<ll> suf(n+1,1);
        for(int i=0;i<n;i++){
            pref[i+1]=pref[i]*nums[i];
        }
        for(int i=n;i>0;i--){
            suf[i-1]=suf[i]*nums[i-1];
        }
        vector<ll> ans(n);
        for(int i=0;i<n;i++){
            ans[i]=pref[i]*suf[i+1];
        }
        return ans;
    }
};


// { Driver Code Starts.
int main()
 {
    int t;  // number of test cases
    cin>>t;
    while(t--)
    {
        int n;  // size of the array
        cin>>n;
        vector<long long int> arr(n),vec(n);
        
        for(int i=0;i<n;i++)    // input the array
        {
            cin>>arr[i];
        }
        Solution obj;
        vec = obj.productExceptSelf(arr,n);   // function call
        
        for(int i=0;i<n;i++)    // print the output
        {
            cout << vec[i] << " ";
        }
        cout<<endl;
    }
	return 0;
}  // } Driver Code Ends