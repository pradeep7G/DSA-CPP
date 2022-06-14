// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};


 // } Driver Code Ends
//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/


class Solution
{
    public:
    //Function to get the maximum total value in the knapsack.
   static bool comp(Item a,Item b){
        double aratio=(double)a.value/(double)a.weight;
        double bratio=(double)b.value/(double)b.weight;
        return aratio > bratio;
    }
    double fractionalKnapsack(int w, Item arr[], int n)
    {
        sort(arr,arr+n,comp);
        double res=0;
        for(int i=0;i<n;i++){
            if(w>=arr[i].weight){
                w-=arr[i].weight;
                res+=arr[i].value;
            }
            else{
                res+=arr[i].value*(((double)w)/(double)(arr[i].weight));
                break;
            }
        }
        return res;
    }
        
};


// { Driver Code Starts.
int main()
{
	int t;
	//taking testcases
	cin>>t;
	cout<<setprecision(2)<<fixed;
	while(t--){
	    //size of array and weight
		int n, W;
		cin>>n>>W;
		
		Item arr[n];
		//value and weight of each item
		for(int i=0;i<n;i++){
			cin>>arr[i].value>>arr[i].weight;
		}
		
		//function call
		Solution ob;
		cout<<ob.fractionalKnapsack(W, arr, n)<<endl;
	}
    return 0;
}  // } Driver Code Ends