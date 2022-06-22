// { Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
class Solution{

    // Function to find the trapped water between the blocks.
    public:
    long long trappingWater(int arr[], int n){
       int lmax[n],rmax[n];
       lmax[0]=arr[0];
       for(int i=1;i<n;i++){
           lmax[i]=max(lmax[i-1],arr[i]);
       }
       rmax[n-1]=arr[n-1];
       for(int i=n-2;i>=0;i--){
           rmax[i]=max(rmax[i+1],arr[i]);
       }
       long long ans=0;
       for(int i=0;i<n;i++){
           ans+=min(rmax[i],lmax[i])-arr[i];
       }
       return ans;
    }
};

// { Driver Code Starts.

int main(){
    
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        
        int a[n];
        
        //adding elements to the array
        for(int i =0;i<n;i++){
            cin >> a[i];            
        }
        Solution obj;
        //calling trappingWater() function
        cout << obj.trappingWater(a, n) << endl;
        
    }
    
    return 0;
}  // } Driver Code Ends