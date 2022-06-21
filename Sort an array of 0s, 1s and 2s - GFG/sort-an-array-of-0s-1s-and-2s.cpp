// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



 // } Driver Code Ends
class Solution
{
    public:
    void sort012(int a[], int n)
    {
        // 2 2 1 0 1
        int left=0,right=n-1,unknown=0;
        while(unknown<=right){
            if(a[unknown]==0){
                swap(a[unknown++],a[left++]);
            }
            else if(a[unknown]==2){
                swap(a[unknown],a[right--]);
            }
            else{
                unknown++;
            }
        }
    }
    
};

// { Driver Code Starts.
int main() {

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >>n;
        int a[n];
        for(int i=0;i<n;i++){
            cin >> a[i];
        }

        Solution ob;
        ob.sort012(a, n);

        for(int i=0;i<n;i++){
            cout << a[i]  << " ";
        }

        cout << endl;
        
        
    }
    return 0;
}

  // } Driver Code Ends