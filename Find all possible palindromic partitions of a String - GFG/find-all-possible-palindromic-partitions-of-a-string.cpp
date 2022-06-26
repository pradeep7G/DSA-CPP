// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  bool is_palindrome(string &s,int start,int end){
      for(int i=start,j=end;i<j;i++,j--){
          if(s[i]!=s[j])
           return false;
      }
      return true;
  }
    void solve(vector<vector<string>> &all,vector<string> &cur,int start,int n,string &s){
        if(start>=n){
            all.push_back(cur);
            return ;
        }
        for(int i=start;i<n;i++){
            if(is_palindrome(s,start,i)){
                cur.push_back(s.substr(start,i-start+1));
                solve(all,cur,i+1,n,s);
                cur.pop_back();
            }
        }
    }
    vector<vector<string>> allPalindromicPerms(string S) {
        vector<vector<string>> all_partitions;
        vector<string> cur_partitions;
        solve(all_partitions,cur_partitions,0,S.length(),S);
        return all_partitions;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        
        cin>>S;

        Solution ob;
        vector<vector<string>> ptr = ob.allPalindromicPerms(S);
        
        for(int i=0; i<ptr.size(); i++)
        {
            for(int j=0; j<ptr[i].size(); j++)
            {
                cout<<ptr[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}  // } Driver Code Ends