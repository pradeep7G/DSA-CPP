class Solution {
public:
    int furthestBuilding(vector<int>& h, int bricks, int ladders) {
       int n=size(h);
       priority_queue<int,vector<int>,greater<int>> pq;
       int i=0;
       while(i < n-1 && pq.size()<ladders){
           if(h[i+1]-h[i]>0)
           {
               pq.push(h[i+1]-h[i]);
           }
            i++;
       }
       while(i<n-1){
           int jumpheight=h[i+1]-h[i];
           if(jumpheight<=0)
           {i++;continue;}
           if(!pq.empty() && pq.top() < jumpheight){
               bricks-=pq.top();
               pq.pop();
               pq.push(jumpheight);
           }
           else
           {
               bricks-=jumpheight;
           }
           if(bricks<0)
               return i;
           i++;
       }
        return i;
    }
};