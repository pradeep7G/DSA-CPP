// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution{   
public:
    int minimumNumberOfSwaps(string s){
        // int open=0,close=0,unbalance=0,n=s.length();
        // int i=0,res=0;
        // while(i<n){
        //     if(s[i]=='['){
        //         open++;
        //         if(unbalance>0){
        //             res+=unbalance;
        //         }
        //     }else{
        //         close++;
        //     }
        //     unbalance=close-open;
        //     i++;
        // }
        // return res;
        int close=0,open=0,unbalance=0,res=0;
        int n=s.length();
        for(int i=0;i<n;i++){
            if(s[i]=='['){
                open++;
                if(unbalance>0)
                 res+=unbalance;
            }
            else{
                close++;
            }
            unbalance=close-open;
        }
        return res;
    }
};

// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.minimumNumberOfSwaps(S) << endl;
    }
    return 0; 
}   // } Driver Code Ends