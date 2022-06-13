// { Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//Back-end complete function Template for C++

class Solution{
    struct Node {
    int data;
    Node *left, *right;
};
 
// A utility function to create a new BST node
Node* newNode(int item)
{
    Node* temp = new Node;
    temp->data = item;
    temp->left = temp->right = NULL;
 
    return temp;
}
    public:
    Node* insert(Node* root,int key,int &suc){
        if(!root){
            return root=newNode(key);
        }
        if(root->data > key){
            suc=root->data;
            root->left=insert(root->left,key,suc);
        }
        else{
            root->right=insert(root->right,key,suc);
        }
        return root;
    }
    vector<int> findLeastGreater(vector<int>& arr, int n) {
        //insert into binary from right to left and store successor;
        //Method-2 iterate from right to left and insert into a set and find upperbound element of current element to find least greater;
        set<int> s;
        for(int i=n-1;i>=0;i--){
            auto it=s.upper_bound(arr[i]);
            s.insert(arr[i]);
            if(it!=s.end()){
                arr[i]=*it;
            }
            else{
                arr[i]=-1;
            }
        }
        return arr;
    }
};

// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin >> n;
	    vector<int>arr(n);
	    for(int i = 0 ; i < n; i++){
	        cin >> arr[i];
	    }
	    Solution ob;
	    vector<int> ans = ob.findLeastGreater(arr, n);
	    for(auto it : ans){
	        cout << it << " ";
	    }
	    cout <<endl;
	}
	return 0;
}
  // } Driver Code Ends