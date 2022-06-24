// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int inSequence(int a, int b, int c){
      if(c==0){
          if(a==b)
            return 1;
           return 0;
      }
     double k=(double)(b-a)/c + 1;
     if(k>0  && (int)k==k)
     return true;
     return false;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int A, B, C;
        cin>>A>>B>>C;
        
        Solution ob;
        cout<<ob.inSequence(A, B, C)<<endl;
    }
    return 0;
}  // } Driver Code Ends