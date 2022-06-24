// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
#define N 105
using namespace std;
void printArray(vector<int> arr, int size)
{
for (int i=0; i < size; i++)
	cout << arr[i] << " ";
}


 // } Driver Code Ends
//User function Template for C++


class Solution
{
    public:
    //Function to merge k sorted arrays.
    typedef pair<int,pair<int,int>> triplet;
    vector<int> mergeKArrays(vector<vector<int>> arr, int K)
    {
        priority_queue<triplet,vector<triplet>,greater<triplet>> pq;
        // for(auto i:arr){
        //     for(auto j:i)
        //     {
        //         pq.push(j);
        //     }
        // }
        // vector<int> res;
        // while(!pq.empty()){
        //     res.push(pq.front());
        //     pq.pop();
        // }
        // return res;
        
        //Efficient solution
        for(int i=0;i<K;i++){
            pq.push({arr[i][0],{i,0}});
        }
        vector<int> res;
        while(!pq.empty()){
            triplet cur=pq.top();
            pq.pop();
            res.push_back(cur.first);
            int r=cur.second.first;
            int c=cur.second.second;
            if(c+1 < K){
                pq.push({arr[r][c+1],{r,c+1}});
            }
        }
        return res;
    }
    
    
};

// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--){
	    int k;
	    cin>>k;
	    vector<vector<int>> arr(k, vector<int> (k, 0));
	    for(int i=0; i<k; i++){
	        for(int j=0; j<k; j++)
	        {
	            cin>>arr[i][j];
	        }
	    }
	    Solution obj;
    	vector<int> output = obj.mergeKArrays(arr, k);
    	printArray(output, k*k);
    	cout<<endl;
    }
	return 0;
}





  // } Driver Code Ends