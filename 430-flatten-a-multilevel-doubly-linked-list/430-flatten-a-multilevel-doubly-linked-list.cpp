/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* solve(Node* head){
        Node* cur=head;
        Node* lastNode=NULL;
        while(cur){
            if(cur->next==NULL){
                lastNode=cur;
            }
            if(cur->child){
                auto childEnd=solve(cur->child);
                auto parent=cur;
                auto next=cur->next;
                auto child=cur->child;
                parent->next=child;
                child->prev=parent;
                parent->child=NULL;
                if(childEnd)
                childEnd->next=next;
                if(next)
                next->prev=childEnd;
            }
            cur=cur->next;
        }
        return lastNode;
    }
    Node* flatten(Node* head) {
        solve(head);
        return head;
    }
};