// { Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++
class Solution{
    public:
    void dfs(int r,int c,int size,vector<vector<string>> &v,vector<string> &output,vector<vector<string>> &list){
        output[r]=list[r][c];
        if(r==size-1){
            v.push_back({output.begin(),output.end()});
            return ;
        }
        for(int i=0;i<list[r+1].size();i++){
            // if(list[0][i]!="")
            dfs(r+1,i,size,v,output,list);
        }
    }
    vector<vector<string>> sentences(vector<vector<string>>&list){
        //basic dfs variant 
        int r=list.size();
        int c=list[0].size();
        vector<vector<string>> v;
        vector<string> output(r);
        for(int i=0;i<c;i++){
            // if(list[0][i]!="")
            dfs(0,i,r,v,output,list);
        }
        return v;
    }
};


// { Driver Code Starts.
int main()
{
	int t = 1;
	//cin>>t;
	while(t--)
	{
	    int m, n;
	    cin >> m >> n;
	    vector<vector<string>>list(m, vector<string>(n));
	    for(int i = 0 ; i < m; i++){
	        for(int j = 0; j < n; j++){
	            cin >> list[i][j];
	        }
	    }
	    Solution ob;
	    vector<vector<string>>ans = ob.sentences(list);
	    for(auto it : ans){
	        for(auto it1 : it){
	            cout << it1 << " ";
	        }
	        cout << endl;
	    }
	}
	return 0;
}
  // } Driver Code Ends