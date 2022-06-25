// { Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution{
  public:
    vector<vector<string> > Anagrams(vector<string>& string_list) {
        //code here
        vector<vector<string>> v;
        vector<string> s_list=string_list;
        unordered_map<string,vector<string>> mp;
        for(int i=0;i<s_list.size();i++){
            sort(s_list[i].begin(),s_list[i].end());
        }
        int n=s_list.size();
        for(int i=0;i<n;i++){
            mp[s_list[i]].push_back(string_list[i]);
        }
        for(auto i:mp){
            v.push_back({i.second.begin(),i.second.end()});
        }
        return v;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<string> string_list(n);
        for (int i = 0; i < n; ++i)
            cin>>string_list[i]; 
        Solution ob;
        vector<vector<string> > result = ob.Anagrams(string_list);
        sort(result.begin(),result.end());
        for (int i = 0; i < result.size(); i++)
        {
            for(int j=0; j < result[i].size(); j++)
            {
                cout<<result[i][j]<<" ";
            }
            cout<<"\n";
        }
    }

    return 0;
}
  // } Driver Code Ends