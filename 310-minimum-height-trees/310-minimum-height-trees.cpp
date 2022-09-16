class Solution {
public:
    vector<int> solve(int n,vector<vector<int>> &edges){
       vector<vector<int>> g(n);
       if(n==1)
           return {0};
       for(int i=0;i<n-1;i++){
           g[edges[i][0]].push_back(edges[i][1]);
           g[edges[i][1]].push_back(edges[i][0]);
       }
       vector<int> leaves;
       for(int i=0;i<n;i++){
           if(g[i].size()==1)
               leaves.push_back(i);
       }
       int nodes=n;
       while(nodes>2){
             nodes-=leaves.size();
             vector<int> newLeaves;
             for(int i=0;i<leaves.size();i++){
                 int leaf=leaves[i];
                 int parent=g[leaf][0];
                 g[leaf].erase(begin(g[leaf]));
                 g[parent].erase(find(begin(g[parent]),end(g[parent]),leaf));
                 if(g[parent].size()==1)
                    newLeaves.push_back(parent);
            }
         leaves=newLeaves;
        }
        return leaves;
    }
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        //how many possible trees with min height, let's say there are n nodes, n is odd, and any node as root in graph with given edges
        //there can be atmost 2 roots that can form mht coz if there are more than 2,let's say 3, it can't be possible
        //ex : - - - - - for this only middle element can form mht, - - - - for this 2,3 nodes can form mht
        //we start by removing leaves until we left with <=2 nodes
        
        return solve(n,edges);
        
/* -----------------------------------------------------------------------------------------------*/
        if(n==1)
            return {0};
        vector<int> res;
        vector<vector<int>> g(n);
        vector<int> degree(n,0);
        for(int i=0;i<n-1;i++){
            g[edges[i][0]].push_back(edges[i][1]);
            g[edges[i][1]].push_back(edges[i][0]);
        }
        vector<int> leaves;
        for(int i=0;i<n;i++){
            if(g[i].size()==1){
                leaves.push_back(i);
            }
        }
        int nodes=n;
        while(nodes>2){
            nodes-=leaves.size();
            vector<int> newleaves;
           for(int i=0;i<leaves.size();i++){
               int leaf=leaves[i];
               int parent=g[leaf][0];
               g[leaf].erase(g[leaf].begin());
               g[parent].erase(find(g[parent].begin(),g[parent].end(),leaf)); //erase(position) or erase(startPosition,endPosition), positions are passed as iterators;
               if(g[parent].size()==1){
                   newleaves.push_back(parent);
               }
           }
           leaves=newleaves;
        }
        return leaves;
        return res;
    }
};