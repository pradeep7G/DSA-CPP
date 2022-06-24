// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution {
  public:
  int palindrome(string s,int i,int j){
      
     while(i>=0 && j<s.length()){
         if(s[i]!=s[j]){
             break;
         }
         else{
             j++;i--;
         }
     }
     return j-i-1;
  }
    string longestPalin (string str) {
      //expand around the center or dp;
    //   string res="";
    //   int maxlen=INT_MIN;
    //   int index=-1;
    //   for(int i=0;i<s.length();i++){
    //       int a=palindrome(s,i,i);
    //       int b=palindrome(s,i,i+1);
    //       int maxl=max(a,b);
    //       if(maxlen<maxl){
    //           maxlen=maxl;
    //           index=i-(maxl-1)/2;
    //       }
    //   }
    //   return s.substr(index,maxlen);
        int n=str.length();
        vector<vector<bool>> dp(n,vector<bool> (n,false));
        for(int i=0;i<n;i++){
            dp[i][i]=true;
        }
        int maxlen=1,index=0;
        for(int i=n-1;i>=0;i--){
            for(int j=i+1;j<n;j++){
                if(str[i]==str[j]){
                    if(i+1 == j){
                     dp[i][j]=true;
                        
                    }
                    else{
                    dp[i][j]=dp[i+1][j-1];
                    }
                    if(dp[i][j]){
                        if(j-i+1 >= maxlen){
                            maxlen=j-i+1;
                            index=i;
                        }
                    }
                }
            }
        }
        return str.substr(index,maxlen);
    }
};

// { Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;
        
        Solution ob;
        cout << ob.longestPalin (S) << endl;
    }
}
// Contributed By: Pranay Bansal
  // } Driver Code Ends