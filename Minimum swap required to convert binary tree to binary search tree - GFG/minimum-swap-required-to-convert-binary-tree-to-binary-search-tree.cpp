// { Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++
class Solution{
  public:
    void inorder(vector<int> &v,int index,vector<int> &a){
        if(index>=a.size())
         return ;
        inorder(v,2*index+1,a);
        v.push_back(a[index]);
        inorder(v,2*index+2,a);
    }
    int min_swaps(vector<int> &v,int n){
        vector<int> tmp(n);
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++){
            tmp[i]=v[i];
            mp[v[i]]=i;
        }
        sort(tmp.begin(),tmp.end());
        int count=0;
        for(int i=0;i<n;i++)
        {
            if(mp[tmp[i]]==i)
             continue;
             else{
                 int elem=v[i];
                 swap(v[i],v[mp[tmp[i]]]);
                 mp[elem]=mp[tmp[i]];
                 mp[tmp[i]]=i;
                 count++;
             }
        }
        return count;
    }
    int minSwaps(vector<int>&a, int n){
        //Write your code here
        vector<int> v;
        inorder(v,0,a);
        return min_swaps(v,n);
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
	    cin >> n;
	    vector<int>A(n);
	    for(int i = 0 ; i < n; i++){
	        cin >> A[i];
	    }
	    Solution ob;
	    int ans = ob.minSwaps(A, n);
	    cout << ans<<endl;
	}
	return 0;
}
  // } Driver Code Ends