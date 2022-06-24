// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution{
  public:
     // Function to find majority element in the array
    // a: input array
    // size: size of input array
    int majorityElement(int a[], int size)
    {
        
        int x=INT_MIN,cx=0;
    for(int i=0;i<size;i++){
        if(x==a[i]){
            cx++;
        }
        else if(!cx){
            x=a[i],cx=1;
        }
        else
            cx--;
    }
    cx=0;
    for(int i=0;i<size;i++){
        if(a[i]==x)
            cx++;
    }
    if(cx>size/2){
        return x;
    }
    return -1;
        
    }
};

// { Driver Code Starts.

int main(){

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        int arr[n];
        
        for(int i = 0;i<n;i++){
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.majorityElement(arr, n) << endl;
    }

    return 0;
}
  // } Driver Code Ends