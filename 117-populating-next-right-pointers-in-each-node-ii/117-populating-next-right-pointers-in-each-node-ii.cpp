/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* constantSpace(Node* root){
        if(!root)
            return root;
       //Can you do it in constant space;
        //traversing through parent node's next and connecting the left and right childs of the next level
        // repeating same for all levels
       Node* cur=root;
       while(cur){
           Node *dummy=new Node(-1e5);
           Node *tmp=dummy;
           while(cur){
              if(cur->left){
                  dummy->next=cur->left;
                  dummy=dummy->next;
              }
              if(cur->right){
                  dummy->next=cur->right;
                  dummy=dummy->next;
              }
              cur=cur->next;
           }
           cur=tmp->next;
       }
       return root;
    }
    Node* optimalPractice(Node* root){
        if(!root)
            return root;
        Node* cur=root;
        while(cur){
            Node* dummy=new Node(-1e5);
            Node* trav=dummy;
            while(cur){
                if(cur->left){
                    trav->next=cur->left;
                    trav=trav->next;
                }
                if(cur->right){
                    trav->next=cur->right;
                    trav=trav->next;
                }
                cur=cur->next;
            }
            cur=dummy->next;
        }
        return root;
    }
    Node* connect(Node* root) {
        if(!root)
            return root;
       //levelorder traversal
        return optimalPractice(root);
        queue<Node *> q;
        q.push(root);
        while(!q.empty()){
            int size=q.size()-1;
            auto prev=q.front();
            q.pop();
            if(prev->left){
                q.push(prev->left);
            }
            if(prev->right){
                q.push(prev->right);
            }
            for(int i=0;i<size;i++){
                auto next=q.front();
                q.pop();
                prev->next=next;
                prev=next;
                if(prev->left){
                    q.push(prev->left);
                }
                if(prev->right){
                    q.push(prev->right);
                }
            }
        }
        return root;
    }
};