// { Driver Code Starts
// Program to find minimum number of platforms
// required on a railway station
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    int findPlatform(int arr[], int dep[], int n)
    {
    //   sort(arr,arr+n);
    //   sort(dep,dep+n);
    //   int i=1,j=0;
    //   int platformsneeded=1;
    //   int result=1;
    //   while(i<n && j<n){
    //       if(arr[i]<=dep[j]){
    //           platformsneeded++;
    //           i++;
    //       }
    //       else if(arr[i] > dep[j]){
    //           platformsneeded--;
    //           j++;
    //       }
    //       result=max(result,platformsneeded);
    //   }
    //   return result;
    
    multiset<pair<int,int>> order;
    for(int i=0;i<n;i++){
        order.insert({arr[i],'a'});
        order.insert({dep[i],'d'});
    }
    int count_platforms=0;
    int max_platforms=0;
    for(auto it:order){
        if(it.second=='a')
         count_platforms++;
        else
         count_platforms--;
        max_platforms=max(max_platforms,count_platforms);
    }
    return max_platforms;
    }
};


// { Driver Code Starts.
// Driver code
int main()
{
    int t;
    cin>>t;
    while(t--) 
    {
        int n;
        cin>>n;
        int arr[n];
        int dep[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        for(int j=0;j<n;j++){
            cin>>dep[j];
        }
        Solution ob;
        cout <<ob.findPlatform(arr, dep, n)<<endl;
    } 
   return 0;
}  // } Driver Code Ends