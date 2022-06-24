// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

// A : given string to search
// B : vector of available strings

class Solution
{
public:
    int wordBreak(string a, vector<string> &b) {
        // unordered_map<string,int> mp;
        // for(auto x:b){
        //     mp[x]++;
        // }
        // vector<bool> dp(a.length()+1,false); //true if a valid word end at i, dp[i]=true;
        // dp[0]=true;
        // int n=a.length();
        // for(int i=1;i<=n;i++){
        //     for(int j=i-1;j>=0;j--){
        //         if(dp[j]){
        //             string s=a.substr(j,i-j);
        //             if(mp[s]){
        //                 dp[i]=true;
        //                 break;
        //             }
        //         }
        //     }
        // }
        // return dp[n];
        unordered_map<string,int> mp;
        int n=a.length();
        for(auto x:b){
            mp[x]++;
        }
        vector<bool> dp(n+1,false); //true if a valid word formed from strings of b end at i, else false;
        dp[0]=true;
        for(int i=1;i<=n;i++){
            for(int j=i-1;j>=0;j--){
                if(dp[j]){
                    string str=a.substr(j,i-j);
                    if(mp[str]){
                        dp[i]=true;
                        break;
                    }
                }
            }
        }
        return dp[n];
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> dict;
        for(int i=0;i<n;i++){
            string S;
            cin>>S;
            dict.push_back(S);
        }
        string line;
        cin>>line;
        Solution ob;
        cout<<ob.wordBreak(line, dict)<<"\n";
    }
}
  // } Driver Code Ends