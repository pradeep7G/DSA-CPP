// { Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    int buyMaximumProducts(int n, int k, int price[]){
      multiset<pair<int,int>> stocks;
      for(int i=0;i<n;i++){
          stocks.insert({price[i],i+1});
      }
      int max_stocks=0;
      int rem_amount=k;
      for(auto i:stocks){
          if(rem_amount - (i.second * i.first) >=0 ){
              rem_amount-=(i.second * i.first);
              max_stocks+=i.second;
          }
          else{
              int can_buy=rem_amount/i.first;
              rem_amount-=(i.first * can_buy);
              max_stocks+=can_buy;
          }
      }
      return max_stocks;
    }
};


// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n, k;
	    cin >> n >> k;
	    int price[n];
	    for(int i = 0 ; i < n; i++){
	        cin >> price[i];
	    }
	    Solution ob;
	    int ans = ob.buyMaximumProducts(n, k, price);
	    cout << ans<<endl;
	}
	return 0;
}
  // } Driver Code Ends