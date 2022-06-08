// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	public:
	vector<string> v;
	set<string> se;
	void permute(string s,int i){
	    if(i==s.length())
	    {
	        se.insert(s);
	        return ;
	    }
	    for(int k=i;k<s.length();k++)
	    {
	        swap(s[i],s[k]);
	        permute(s,i+1);
	        swap(s[i],s[k]);
	    }
	}
	vector<string>find_permutation(string s)
	{
	    permute(s,0);
	    for(auto x:se)
	     v.push_back(x);
	    return v;
	}
};



// { Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}
  // } Driver Code Ends