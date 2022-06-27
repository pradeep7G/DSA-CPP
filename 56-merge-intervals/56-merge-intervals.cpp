class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& i) {
       vector<vector<int>> v;
       sort(i.begin(),i.end(),[&](auto a,auto b){
          return a[0]<b[0];
       });
       v.push_back(i[0]);
       auto prev=i[0];
       for(int j=1;j<i.size();j++){
           if(prev[1]<i[j][0]){
               v.push_back(i[j]);
               prev=i[j];
           }
           else{
               v.back()[1]=max(v.back()[1],i[j][1]);
               prev=v.back();
           }
       }
       return v;
    }
};