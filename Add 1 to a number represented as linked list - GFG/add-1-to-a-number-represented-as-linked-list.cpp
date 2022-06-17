// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h> 
using namespace std; 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data; 
        node = node->next; 
    }  
    cout<<"\n";
} 


 // } Driver Code Ends
//User function template for C++

/* 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    Node* addOne(Node *head) 
    {
        Node *prev=NULL,*cur=head;
        while(cur){
            Node *temp=cur->next;
            cur->next=prev;
            prev=cur;
            cur=temp;
        }
        int carry=1;
        Node *newHead=prev;
        while(newHead){
            int val=(newHead->data + carry);
            newHead->data=val %10;
            newHead=newHead->next;
            carry=val/10;
            if(carry==0)
             break;
        }
        cur=prev;
        Node *prev2=NULL;
        while(cur){
            Node *temp=cur->next;
            cur->next=prev2;
            prev2=cur;
            cur=temp;
        }
        if(carry){
            Node* newNode=new Node(1);
            newNode->next=prev2;
            return newNode;
        }
        else{
            return prev2;
        }
    }
};

// { Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        
        Node* head = new Node( s[0]-'0' );
        Node* tail = head;
        for(int i=1; i<s.size(); i++)
        {
            tail->next = new Node( s[i]-'0' );
            tail = tail->next;
        }
        Solution ob;
        head = ob.addOne(head);
        printList(head); 
    }
    return 0; 
} 
  // } Driver Code Ends