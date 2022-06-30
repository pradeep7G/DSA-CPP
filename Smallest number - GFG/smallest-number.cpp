// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution{   
public: 
    bool check(int n,int sum){
        //()
        int s=0,d=n;
        while(d){
            s+=(d%10);
            d/=10;
        }
        return s==sum;
    }
    string smallestNumber(int s, int d){
       if(s>9*d || (s==0 && d>1)){
           return "-1";
       }
       string ans="";
       s-=1;
       for(int j=d-1;j>0;j--){
           if(s>9){
               ans=ans+"9";
               s-=9;
           }
           else{
               ans=ans+to_string(s);
               s=0;
           }
       }
       s+=1;
       ans=ans+to_string(s);
       reverse(begin(ans),end(ans));
       return ans;
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