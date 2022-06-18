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
    Node* copyRandomList(Node* head) {
        unordered_map<Node *,Node *> mp;
        Node *cloneHead=NULL,*cloneTail=NULL,*cur=head;
        while(cur){
            Node *newNode=new Node(cur->val);
            mp[cur]=newNode;
            if(cloneHead==NULL)
            {
                cloneHead=newNode;
                cloneTail=newNode;
            }
            else{
                cloneTail->next=newNode;
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
};