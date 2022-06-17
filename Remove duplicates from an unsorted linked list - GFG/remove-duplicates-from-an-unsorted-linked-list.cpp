// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};

void print(Node *root)
{
Node *temp = root;
while(temp!=NULL)
{
cout<<temp->data<<" ";
temp=temp->next;
}
}


 // } Driver Code Ends
/*
The structure of linked list is the following

struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/


class Solution
{
    public:
    //Function to remove duplicates from unsorted linked list.
    Node * removeDuplicates( Node *head) 
    {
        Node* dummy=new Node(-1);
        Node* newHead=dummy;
        Node *cur=head;
        unordered_map<int,int> mp;
        while(cur){
           if(cur->next){
               if(cur->data==cur->next->data){
                   if(mp[cur->data]==0)
                   {
                   mp[cur->data]=1;
                   newHead->next=cur;
                   newHead=cur;
                   }
                   cur=cur->next;
                   while(cur && newHead->data==cur->data){
                       cur=cur->next;
                   }
               }
               else{
                    if(mp[cur->data]==0)
                   {
                   mp[cur->data]=1;
                   newHead->next=cur;
                   newHead=cur;
                   }
                   cur=cur->next;
               }
           }
           else{
                if(mp[cur->data]==0)
                   {
                   mp[cur->data]=1;
               newHead->next=cur;
               newHead=cur;
                   }
               cur=cur->next;
           }
        }
        newHead->next=NULL;
        return dummy->next;
    }
};


// { Driver Code Starts.

int main() {
	// your code goes here
	int T;
	cin>>T;
	
	while(T--)
	{
		int K;
		cin>>K;
		struct Node *head = NULL;
        struct Node *temp = head;
 
		for(int i=0;i<K;i++){
		int data;
		cin>>data;
			if(head==NULL)
			head=temp=new Node(data);
			else
			{
				temp->next = new Node(data);
				temp=temp->next;
			}
		}
		
	    Solution ob;
		Node *result  = ob.removeDuplicates(head);
		print(result);
		cout<<endl;
		
	}
	return 0;
}  // } Driver Code Ends