class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& i) {
       vector<vector<int>> v;
       sort(i.begin(),i.end(),[&](auto a,auto b){
          return a[0]<b[0];
       });
       auto prev=i[0];
       for(int j=1;j<i.size();j++){
           if(prev[1]>=i[j][0]){
               prev[1]=max(prev[1],i[j][1]);
           }
           else{
              v.push_back(prev);
              prev=i[j];
           }
       }
        v.push_back(prev);
       return v;
    }
};