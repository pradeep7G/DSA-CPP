// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

// Function to Build Tree
Node* buildTree(string str)
{
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str; )
        ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


 // } Driver Code Ends


/*
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/
class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    map<int,int> mp;
    map<int,pair<int,int>> m;
    vector<int> iterative(Node *root){
        if(!root)
            return {};
        map<int,int> mp;
        queue<pair<Node *,int>> q;
        q.push({root,0});
        while(!q.empty()){
            auto p=q.front();
            q.pop();
            if(mp.find(p.second)==mp.end()){
                mp[p.second]=p.first->data;
            }
            if(p.first->left){
                q.push({p.first->left,p.second-1});
            }
            if(p.first->right){
                q.push({p.first->right,p.second+1});
            }
        }
        vector<int> res;
        for(auto m:mp)
         res.push_back(m.second);
        return res;
    }
    void recursive(Node* root,int d,int l){
        if(!root)
            return ;
        if(m.count(d)==0){
            m[d]={root->data,l};
        }
        else if(m[d].second > l){
            m[d]={root->data,l};
        }
        recursive(root->left,d-1,l+1);
        recursive(root->right,d+1,l+1);
    }
    vector<int> topView(Node *root)
    {
        // map<int,int> mp;
        mp.clear();
        // queue<pair<Node *,int>> q;
        // q.push({root,0});
        // while(!q.empty()){
        //     auto p=q.front();
        //     q.pop();
        //     Node* temp=p.first;
        //     int i=p.second;
        //     if(mp.find(i)==mp.end()){
        //         mp[i]=temp->data;
        //     }
        //     if(temp->left)
        //     {
        //         q.push({temp->left,i-1});
        //     }
        //     if(temp->right){
        //         q.push({temp->right,i+1});
        //     }
        // }
        recursive(root,0,0);
        vector<int> ans;
        for(auto p:m){
            ans.push_back(p.second.first);
        }
        return ans;
    }

};



// { Driver Code Starts.

int main() {
    int tc;
    cin>>tc;
    cin.ignore(256, '\n');
    while (tc--) {
        string treeString;
        getline(cin, treeString);
        Solution ob;
        Node *root = buildTree(treeString);
        vector<int> vec = ob.topView(root);
        for(int x : vec)
            cout<<x<<" ";
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends