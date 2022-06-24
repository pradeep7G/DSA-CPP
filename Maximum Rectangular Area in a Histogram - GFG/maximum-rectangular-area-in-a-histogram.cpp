// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to find largest rectangular area possible in a given histogram.
    long long getMaxArea(long long arr[], int n)
    {
        long long res=0;
        vector<int> leftsmaller(n,-1),rightsmaller(n,n);
        stack<int> s;
        s.push(-1);
        for(int i=0;i<n;i++){
            while(!s.empty() && s.top()!=-1 && arr[s.top()]>arr[i]){
                rightsmaller[s.top()]=i;
                s.pop();
            }
            if(i>0 && arr[i]==arr[i-1]){
                leftsmaller[i]=leftsmaller[i-1];
            }
            else{
                leftsmaller[i]=s.top();
            }
            s.push(i);
        }
        for(int i=0;i<n;i++){
            res=max(res,arr[i]*(rightsmaller[i]-leftsmaller[i]-1));
        }
        return res;
    }
};


// { Driver Code Starts.

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.getMaxArea(arr, n)<<endl;
    
    }
	return 0;
}
  // } Driver Code Ends