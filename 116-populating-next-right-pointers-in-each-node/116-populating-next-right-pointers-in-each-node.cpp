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
    Node* connectt(Node *root){
        if(!root)
            return NULL;
        if(root->left)
            root->left->next=root->right;
        if(root->right && root->next)
            root->right->next=root->next->left;
        connectt(root->left);
        connectt(root->right);
        return root;
    }
    Node* connect(Node* root) {
        //we can level order traversal
        // queue<Node *> q;
        // q.push(root);
        // while(!q.empty()){
        //     int size=q.size();
        //     Node* prev=NULL;
        //     for(int i=0;i<size;i++){
        //         auto front=q.front();
        //         q.pop();
        //         if(prev){
        //             prev->next=front;
        //         }
        //         prev=front;
        //         if(front){
        //          q.push(front->left);
        //          q.push(front->right);
        //         }
        //     }
        // }
        connectt(root);
        return root;
    }
};