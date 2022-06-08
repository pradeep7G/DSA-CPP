// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution {
  public:
    int romanToDecimal(string &str) {
       int ans=0;
       unordered_map<char,int> num;
       num['I'] = 1;
       num['V'] = 5;
       num['X'] = 10;
       num['L'] = 50;
       num['C'] = 100;
       num['D'] = 500;
       num['M'] = 1000;
       
       for(int i=str.length()-1;i>=0;i--)
       {
           if(i<str.length()-1 && num[str[i]]<num[str[i+1]]){
               ans-=num[str[i]];
           }else{
               ans+=num[str[i]];
           }
       }
       return ans;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.romanToDecimal(s) << endl;
    }
}  // } Driver Code Ends