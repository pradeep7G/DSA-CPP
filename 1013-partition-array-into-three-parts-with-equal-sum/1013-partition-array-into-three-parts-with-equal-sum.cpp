class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& arr) {
        int totalSum=accumulate(arr.begin(),arr.end(),0);
        if(totalSum%3!=0)return false;
        int target=totalSum/3;
        int sum=0;
        for(int i=0;i<arr.size();i++)
        {
            sum+=arr[i];
            if(sum==target)
            {
                int innerSum=0;
                for(int j=i+1;j<arr.size();j++)
                {
                    innerSum+=arr[j];
                    if(j<arr.size()-1 && innerSum==target && (totalSum-innerSum-sum)==target)
                        return true;
                }
            }
        }
        return false;
    }
};