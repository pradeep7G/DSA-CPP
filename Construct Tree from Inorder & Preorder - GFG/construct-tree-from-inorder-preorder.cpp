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
    Node* constructtree(int &index,int pre[],unordered_map<int,int> &inorder,int start,int end){
        if(start>end)
            return NULL;
        Node* root=new Node(pre[index]);
        int rootindex=inorder[pre[index++]];
          if(start==end)
            return root;
        root->left=constructtree(index,pre,inorder,start,rootindex-1);
        root->right=constructtree(index,pre,inorder,rootindex+1,end);
        return root;
    }
    Node* buildTree(int in[],int pre[], int n)
    {
       unordered_map<int,int> mp;
       for(int i=0;i<n;i++){
           mp[in[i]]=i;
       }
       int index=0;
       int end=n-1;
       return constructtree(index,pre,mp,index,end);
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