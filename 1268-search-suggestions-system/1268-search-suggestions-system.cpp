class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        sort(products.begin(),products.end());
        vector<vector<string>> res;
        string search="";
        for(int i=0;i<searchWord.length();i++){
            auto it=lower_bound(products.begin(),products.end(),searchWord.substr(0,i+1));
            auto end=lower_bound(it,min(it+3,products.end()),searchWord.substr(0,i)+(char)(searchWord[i]+1));
            res.push_back({it,end});
        }
        return res;
    }
};