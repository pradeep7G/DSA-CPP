// { Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    int minChar(string str){
        int n=str.length();
        vector<int> lps(2*n+1);
        string rev=str;
        reverse(rev.begin(),rev.end());
        string s=str+'$'+rev;
        computelps(lps,s);
        return n-lps[2*n];
    }
    void computelps(vector<int> &lps,string s){
        lps[0]=0;
        int i=1;
        int len=0;
        int n=s.length();
        while(i<n){
            if(s[i]==s[len]){
                len++;
                lps[i]=len;
                i++;
            }
            else{
                if(len!=0){
                    len=lps[len-1];
                }
                else{
                    lps[i]=0;
                    i++;
                }
            }
        }
        return ;
    }
};


// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    string str;
	    cin >> str;
	    Solution ob;
	    int ans = ob.minChar(str);
	    cout << ans<<endl;
	}
	return 0;
}
  // } Driver Code Ends