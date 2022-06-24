// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution
{
    public:
        int findzeros(int num){
            int count=0;
            int n=num;
            while(n){
                count+=(n/5);
                n/=5;
            }
            return count;
        }
        int findNum(int n)
        {
          int lo=0,hi=5*n;
          while(lo<=hi){
              int mid=lo+(hi-lo)/2;
              int zeros=findzeros(mid);
              if(zeros==n && mid%5==0)
              return mid;
              if(zeros < n){
                  lo=mid+1;
              }
              else
                 hi=mid-1;
          }
          return lo;
        }
};

// { Driver Code Starts.


int main() {
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        Solution ob;
        cout <<ob.findNum(n) << endl;
    }
return 0;
}  // } Driver Code Ends