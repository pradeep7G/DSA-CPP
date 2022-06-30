// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

	public:
	int minCoins(int coins[], int M, int V) 
	{ 
	    //dp[V]=1+min({dp[v-coins[i}) i ==> (0,m);
	    vector<int> dp(V+1,INT_MAX);
	    dp[0]=0;
	    for(int i=1;i<=V;i++){
	        for(int j=0;j<M;j++){
	            if(coins[j]<=i){
	                if(dp[i-coins[j]]!=INT_MAX)
	                dp[i]=min(1+dp[i-coins[j]],dp[i]);
	            }
	        }
	    }
	    if(dp[V]==INT_MAX)
	    return -1;
	    return dp[V];
	} 
	  
};

// { Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int v, m;
        cin >> v >> m;

        int coins[m];
        for(int i = 0; i < m; i++)
        	cin >> coins[i];

      
	    Solution ob;
	    cout << ob.minCoins(coins, m, v) << "\n";
	     
    }
    return 0;
}
  // } Driver Code Ends