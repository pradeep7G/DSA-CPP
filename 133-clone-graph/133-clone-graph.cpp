/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    // Node* dfs(Node* cur,unordered_map<Node*,Node*> &mp){
    //     Node* clone=new Node(cur->val);
    //     mp[cur]=clone;
    //     for(auto i:cur->neighbors){
    //         if(mp.find(i)!=mp.end()){
    //             clone->neighbors.push_back(mp[i]);
    //         }
    //         else{
    //             clone->neighbors.push_back(dfs(i,mp));
    //         }
    //     }
    //     return clone;
    // }
    Node* dfs(Node* cur,unordered_map<Node*,Node*> &mp){
        Node* clone_root=new Node(cur->val);
        mp[cur]=clone_root;
        for(auto i:cur->neighbors){
            if(mp.find(i)!=mp.end()){
                clone_root->neighbors.push_back(mp[i]);
            }
            else{
                clone_root->neighbors.push_back(dfs(i,mp));
            }
        }
        return clone_root;
    }
    Node* cloneGraph(Node* node) {
        // if(!node)
        //     return NULL;
        // if(node->neighbors.size()==0)
        // {
        //     Node* root=new Node(node->val);
        //     return root;
        // }
        // unordered_map<Node*,Node*> mp;
        // return dfs(node,mp);
        if(!node)
            return NULL;
        if(node->neighbors.size()==0){
            Node* root=new Node(node->val);
            return root;
        }
        unordered_map<Node*,Node*> mp;
        return dfs(node,mp);
    }
};