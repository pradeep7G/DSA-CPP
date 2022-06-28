/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* cloneList(Node *head){
        //Two pass, Single Pass??
        unordered_map<Node *,Node *> mp;
        Node *cloneHead=NULL,*cloneTail=NULL;
        Node *cur=head;
        while(cur){
            Node *newnode=new Node(cur->val);
            mp[cur]=newnode;
            if(cloneHead==NULL)
            {
                cloneHead=newnode;
                cloneTail=newnode;
            }
            else{
                cloneTail->next=newnode;
                cloneTail=cloneTail->next;
            }
            cur=cur->next;
        }
        cur=head;
        Node *tmp=cloneHead;
        while(cur && tmp){
            tmp->random=mp[cur->random];
            tmp=tmp->next;
            cur=cur->next;
        }
        return cloneHead;
    }
    Node* copyRandomList(Node* head) {
        unordered_map<Node *,Node *> mp;
        Node *cloneHead=NULL,*cloneTail=NULL,*cur=head;
        while(cur){
            Node *newNode=NULL;
            if(mp.find(cur)!=mp.end()){
                newNode=mp[cur];
            }
            else
            {   
                newNode=new Node(cur->val);
                mp[cur]=newNode;
            }
            if(cloneHead==NULL)
            {
                cloneHead=newNode;
                cloneTail=newNode;
                if(mp.find(cur->random)!=mp.end()){
                    cloneHead->random=mp[cur->random];
                    cloneTail->random=mp[cur->random];
                }
                else{
                    if(cur->random)
                    {
                    Node *node=new Node(cur->random->val);
                    mp[cur->random]=node;
                    cloneHead->random=mp[cur->random];
                    cloneTail->random=mp[cur->random];
                    }
                }
            }
            else{
                cloneTail->next=newNode;
                cloneTail=cloneTail->next;
                if(mp.find(cur->random)!=mp.end()){
                    cloneTail->random=mp[cur->random];
                }
                else{
                     if(cur->random)
                    {
                    Node *node=new Node(cur->random->val);
                    mp[cur->random]=node;
                    cloneTail->random=mp[cur->random];
                     }
                }
            }
            cur=cur->next;
        }
        // cur=head;
        // Node *tmp=cloneHead;
        // while(cur && tmp){
        //     tmp->random=mp[cur->random];
        //     tmp=tmp->next;
        //     cur=cur->next;
        // }
        return cloneHead;
    }
};