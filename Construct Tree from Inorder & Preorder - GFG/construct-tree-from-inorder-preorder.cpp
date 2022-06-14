// { Driver Code Starts
//

#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};


void printPostOrder(Node *root)
{
	if(root==NULL)
		return;
	printPostOrder(root->left);
	printPostOrder(root->right);
	cout<<root->data<<" ";
}

 // } Driver Code Ends


/*Complete the code here.
Node is as follows:
struct Node
{
  int data;
  Node* left;
  Node* right;
};
*/
class Solution{
    public:
    unordered_map<int,int> mp;
    Node* constructtree(int in[],int pre[],int &index,int start,int end){
        if(start > end)
        {
            return NULL;
        }
        int indexinorder=mp[pre[index]];
        Node* root=new Node(pre[index]);
        index++;
        if(end==start){
            return root;
        }
        root->left=constructtree(in,pre,index,start,indexinorder-1);
        root->right=constructtree(in,pre,index,indexinorder+1,end);
        return root;
    }
    Node* buildTree(int in[],int pre[], int n)
    {
        mp.clear();
       for(int i=0;i<n;i++){
           mp[in[i]]=i;
       }
       int index=0;
       Node* root=constructtree(in,pre,index,0,n-1);
       return root;
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
		cin>>n;
		
		int inorder[n], preorder[n];
		for(int i=0; i<n; i++)
			cin>> inorder[i];
		for(int i=0; i<n; i++)
			cin>> preorder[i];
		Solution obj;
		Node *root = obj.buildTree(inorder, preorder, n);
		printPostOrder(root);
		cout<< endl;
	}
}
  // } Driver Code Ends