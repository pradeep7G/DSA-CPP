// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++
struct node{
   node *next[26]={NULL};
   bool isLeaf=false;
};
class trie{
   node *root;
   public:
   trie(){
       root=new node;
   }
   void insert(string &s){
       node *head=root;
       for(int i=0;i<s.size();i++){
           if(!head->next[s[i]-'a']) head->next[s[i]-'a']=new node;
           head=head->next[s[i]-'a'];
       }
       head->isLeaf=true;
   }
   bool search(string &s){
       node *head=root;
       for(int i=0;i<s.size();i++){
           if(!head->next[s[i]-'a']) return false;
           head=head->next[s[i]-'a'];
       }
       return head->isLeaf;
   }
};
class Solution{
   public:
   bool func(string &s,int j,trie *head){
       if(j==s.size()) return true;
       string t;
       for(int i=j;i<s.size();i++){
           t.push_back(s[i]);
           if(head->search(t) and func(s,i+1,head)) return 1;
       }
       return 0;
   }
   int wordBreak(string A, vector<string> &B) {
       //code here
       trie *t=new trie();
       for(auto i:B) t->insert(i);
       return func(A,0,t);
   }
};

// { Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> dict;
        for(int i=0;i<n;i++){
            string S;
            cin>>S;
            dict.push_back(S);
        }
        string line;
        cin>>line;
        Solution ob;
        cout<<ob.wordBreak(line, dict)<<"\n";
    }
}
  // } Driver Code Ends