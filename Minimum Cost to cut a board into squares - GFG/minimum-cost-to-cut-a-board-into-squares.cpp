// { Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution {
public:
    int minimumCostOfBreaking(vector<int> X, vector<int> Y, int M, int N){
        //Write your code here
        sort(X.begin(),X.end(),greater<int>());
        sort(Y.begin(),Y.end(),greater<int>());
        
        int horzn=1,vert=1;
        int i=0,j=0;
        int total_cost=0;
        while(i<M && j<N){
            if(X[i] >= Y[j]){
                total_cost+=horzn * X[i];
                vert++;
                i++;
            }
            else{
                total_cost+=vert * Y[j];
                horzn++;
                j++;
            }
        }
        int total=0;
        while(i < M)
         total += X[i++];
        total_cost+=total * horzn;
        total=0;
        while(j < N){
            total+=Y[j++];
        }
        total_cost+=total * vert;
        return total_cost;
    }
};



// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int m, n;
	    cin >> m >> n;
	    vector<int>X(m - 1), Y(n - 1);
	    for(int i = 0; i < m - 1; i++){
	        cin >> X[i];
	    }
	    for(int i = 0; i < n - 1; i++){
	        cin >> Y[i];
	    }
	    Solution ob;
	    int ans = ob.minimumCostOfBreaking(X, Y, m - 1, n - 1);
	    cout << ans<<endl;
	}
	return 0;
}
  // } Driver Code Ends