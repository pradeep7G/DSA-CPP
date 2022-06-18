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
    Node* flatten(Node* head) {
        Node *cur=head,*prev=NULL;
        while(cur){
            prev=cur;
            if(cur->child){
                Node *child=cur->child;
                Node *flattenedChild=flatten(child);
                Node *tmp=cur->next;
                cur->next=flattenedChild;
                flattenedChild->prev=cur;
                while(child->next){
                    child=child->next;
                }
                child->next=tmp;
                if(tmp)
                    tmp->prev=child;
                prev->child=NULL;
                cur=tmp;
            }
            else
                cur=cur->next;
        }
        return head;
    }
};