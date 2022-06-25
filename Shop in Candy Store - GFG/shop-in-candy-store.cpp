// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{
public:
    vector<int> candyStore(int can[], int n, int k)
    {
       sort(can,can+n);
       int res1=0,res2=0;
       int count=0;
       for(int i=0;i<n;i++){
           res1+=can[i];
           if(count+k+1 >= n){
               break;
           }
           else{
               count+=k+1;
           }
       }
       count=0;
       reverse(can,can+n);
        for(int i=0;i<n;i++){
           res2+=can[i];
           if(count+k+1 >= n){
               break;
           }
           else{
               count+=k+1;
           }
       }
       return {res1,res2};
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, K;
        cin >> N >> K;
        int candies[N];

        for (int i = 0; i < N; i++)
        {
            cin >> candies[i];
        }

        Solution ob;
        vector<int> cost = ob.candyStore(candies, N, K);
        cout << cost[0] << " " << cost[1] << endl;
    }
    return 0;
}  // } Driver Code Ends