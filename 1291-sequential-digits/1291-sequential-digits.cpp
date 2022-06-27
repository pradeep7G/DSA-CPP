class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> res;
        for(int i=1;i<9;i++){
            int digit=i;
            int j=i+1;
            while(digit<low){
                if(j>=10)
                    break;
                digit=digit*10 + j;
                j++;
            }
            while(digit>=low && digit<=high){
                res.push_back(digit);
                if(j>=10)
                    break;
                digit=digit*10 + j;
                j++;
            }
        }
        sort(begin(res),end(res));
        return res;
    }
};