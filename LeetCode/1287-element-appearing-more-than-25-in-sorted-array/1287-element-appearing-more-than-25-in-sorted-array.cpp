class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int cnt=1;
        int occurance;
        if(arr.size()%4!=0)
            occurance=ceil((static_cast<double>(arr.size()))/4.0);
        else
            occurance=(arr.size()/4)+1;
        for(int i=0;i<arr.size();)
        {
            int j;
            for(j=i;j<arr.size()-1 && arr[j]==arr[j+1];j++)cnt++;
            if(cnt>=occurance)return arr[i];
            else{
                cnt=1;i=j+1;
            }
        }
        return arr[0];
    }
};