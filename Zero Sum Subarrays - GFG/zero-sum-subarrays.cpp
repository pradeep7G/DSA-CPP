// { Driver Code Starts
//Initial function template for C++

#include<bits/stdc++.h>
using namespace std;
#define ll long long

 // } Driver Code Ends
//User function template for C++

class Solution{
    public:
    //Function to count subarrays with sum equal to 0.
    ll findSubarray(vector<ll> arr, int n ) {
        unordered_map<int,vector<int>> mp;
        int count=0;
        ll sum=0;
        vector<pair<ll,ll>> res;
        for(int i=0;i<n;i++){
            sum+=arr[i];
            if(sum==0)
            {
             count++;
             res.push_back({0,i});
            }
            if(mp.find(sum)!=mp.end()){
                vector<int> vc=mp[sum];
                for(auto it=vc.begin();it!=vc.end();it++){
                    res.push_back({*it+1,i});
                }
            }
            count+=mp[sum].size();
            mp[sum].push_back(i);
        }
        return count;
        
        //to find all the subarrays;
    }
};

// { Driver Code Starts.
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n; //input size of array
       
        vector<ll> arr(n,0);
        
        for(int i=0;i<n;i++)
            cin>>arr[i]; //input array elements
        Solution ob;
        cout << ob.findSubarray(arr,n) << "\n";
    }
	return 0;
}  // } Driver Code Ends