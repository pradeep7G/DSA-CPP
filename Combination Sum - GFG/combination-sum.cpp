// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution {
  public:
    //Function to return a list of indexes denoting the required 
    //combinations whose sum is equal to given number.
    void solve(int sum,vector<int> &cur,vector<vector<int>> &res,vector<int> &ar,int index){
        if(sum<0 || index>ar.size()){
            return ;
        }
        if(index==ar.size() && sum==0){
            res.push_back(cur);
            return ;
        }
        if(sum==0){
            res.push_back(cur);
            return ;
        }
        while(index<ar.size() && sum-ar[index]>=0){
            cur.push_back(ar[index]);
            solve(sum-ar[index],cur,res,ar,index);
            index++;
            cur.pop_back();
        }
    }
    vector<vector<int> > combinationSum(vector<int> &A, int B) {
        //sort the array
        sort(A.begin(),A.end());
        //remove duplicate
        A.erase(unique(A.begin(),A.end()),A.end());
        
        vector<vector<int>> result;
        vector<int> cur;
        solve(B,cur,result,A,0);
        return result;
    }
};

// { Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> A;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            A.push_back(x);
        }   
        int sum;
        cin>>sum;
        Solution ob;
        vector<vector<int>> result = ob.combinationSum(A, sum);
   		if(result.size()==0){
   			cout<<"Empty";
   		}
        for(int i=0;i<result.size();i++){
            cout<<'(';
            for(int j=0;j<result[i].size();j++){
                cout<<result[i][j];
                if(j<result[i].size()-1)
                    cout<<" ";
            }
            cout<<")";
        }
        cout<<"\n";
    }
}	  // } Driver Code Ends