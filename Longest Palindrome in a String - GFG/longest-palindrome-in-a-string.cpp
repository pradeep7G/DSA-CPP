// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution {
  public:
  int palindrome(string s,int i,int j){
      
      while(i>=0 && j<s.length()){
          if(s[i]!=s[j])
           break;
          else{
              i--;
              j++;
          }
      }
      
      return j-i-1;
      
  }
    string longestPalin (string s) {
        
        int ans=-1;
        int index=-1;
        for(int i=0;i<s.size();i++)
        {
            int val1=palindrome(s,i,i+1); // for even length substring
            int val2=palindrome(s,i,i);// for odd length palindromes
             
            int maxy=max(val1,val2);
            
            if(maxy>ans)
             {
                 ans=maxy;
                 index=i-(maxy-1)/2;
             }
        }
        return s.substr(index,ans);
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