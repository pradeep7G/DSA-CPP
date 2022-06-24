// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int minFlips (string s);
int32_t main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;

        cout << minFlips (s) << endl;
    }
}
// Contributed By: Pranay Bansal
// } Driver Code Ends


int minFlips (string s)
{
    // int ans=0;
    // int count0=0,count1=0;
    //  int ans1=0;
    //  for(int i=0;i<s.length();i++){
    //      if(i&1 && s[i]!='0')
    //       {
    //           ans1++;
    //       }
    //       else if(i%2==0 && s[i]!='1')
    //       {
    //           ans1++;
    //       }
    //  }
    //  for(int i=0;i<s.length();i++){
    //      if(i&1 && s[i]!='1')
    //       {
    //           ans++;
    //       }
    //       else if(i%2==0 && s[i]!='0')
    //       {
    //           ans++;
    //       }
    //  }
    //  return min(ans,ans1);
    int res1=0,res2=0;
    int n=s.length();
    for(int i=0;i<n;i++){
        if(i&1 && s[i]!='0'){
            res1++;
        }
        else if(i%2==0 && s[i]!='1'){
            res1++;
        }
    }
    for(int i=0;i<n;i++){
        if(i&1 && s[i]!='1'){
            res2++;
        }
        else if(i%2==0 && s[i]!='0')
        {
            res2++;
        }
    }
    return min(res1,res2);
}