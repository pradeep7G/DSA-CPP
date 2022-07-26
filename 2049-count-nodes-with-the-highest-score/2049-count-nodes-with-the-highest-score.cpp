class Solution {
public:
    long long ans=0,maxScore=0;
    int dfs(int root,vector<vector<int>> &g,int totalNodes){
        long score=1,count=1;
        for(auto child:g[root]){
            long childCount=dfs(child,g,totalNodes);
            score*=childCount;
            count+=childCount;
        }
        int remaining=totalNodes-count;
        if(remaining)
            score*=remaining;
        if(score>maxScore){
            maxScore=score;
            ans=0;
        }
        if(score==maxScore){
            ans++;
        }
        return count;
    }
    int countHighestScoreNodes(vector<int>& parents) {
        int n=parents.size();
        ans=0;
        int totalNodes=n;
        //construct tree and solve?? wait such a good problem, if we want to create a tree we need to define a new class and left,right pointers, so much hassle right? why don't you just treat it as a graph and implement your algo? YES!!
        vector<vector<int>> g(n);
        for(int i=1;i<n;i++){
            g[parents[i]].push_back(i);  //can be extended to n-ary tree?
        }
        dfs(0,g,totalNodes);
        return ans;
    }
};