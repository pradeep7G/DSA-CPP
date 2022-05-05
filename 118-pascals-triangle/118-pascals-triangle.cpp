class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> pascalTriangle;
        for(int i=0;i<numRows;i++)
        {
            vector<int> curRow;
            for(int j=0;j<=i;j++)
            {
                if(j==0 || j==i)
                    curRow.push_back(1);
                else
                    curRow.push_back(pascalTriangle.back()[j-1]+pascalTriangle.back()[j]);
                    
            }
            pascalTriangle.push_back(curRow);
        }
        return pascalTriangle;
    }
};