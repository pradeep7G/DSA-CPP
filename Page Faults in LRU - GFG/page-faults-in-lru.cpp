// { Driver Code Starts
// Initial Template for C++



#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int pageFaults(int n, int c, int pages[]){
        priority_queue<pair<int,int>> pq;
        set<int> s;
        
        //use pq and set to remove and add elements, you can also do it with standalone vector and insrt and erase operations
        int count=0;
        vector<int> v;
        for(int i=0;i<n;i++){
            auto it=find(v.begin(),v.end(),pages[i]);
            if(it==v.end()){
                if(v.size()==c){
                    v.erase(v.begin());
                }
            v.push_back(pages[i]);
            count++;
            }else{
                v.erase(it);
                v.push_back(pages[i]);
            }
        }
        return count;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, C;
        cin>>N;
        int pages[N];
        for(int i = 0;i < N;i++)
            cin>>pages[i];
        cin>>C;
        
        Solution ob;
        cout<<ob.pageFaults(N, C, pages)<<"\n";
    }
    return 0;
}  // } Driver Code Ends