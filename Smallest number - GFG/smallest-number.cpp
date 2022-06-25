// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution{   
public: 
    bool check(int n,int sum){
        int s=0,d=n;
        while(d){
            s+=(d%10);
            d/=10;
        }
        return s==sum;
    }
    string smallestNumber(int s, int d){
        int lo=pow(10,d-1),hi=pow(10,d)-1;
        for(int i=lo;i<=hi;i++){
            if(check(i,s))
                return to_string(i);
        }
        return "-1";
    }
};

// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int S,D;
        cin >> S >> D;
        Solution ob;
        cout << ob.smallestNumber(S,D) << endl;
    }
    return 0; 
}   // } Driver Code Ends