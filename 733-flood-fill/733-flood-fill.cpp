class Solution {
public:
    void fill(int x,int y,vector<vector<int>> &img,int srccolor,int color,int m,int n){
        if(x<0 || y<0 || x>=m || y>=n || img[x][y]!=srccolor ||img[x][y]==color)
            return ;
        img[x][y]=color;
        fill(x,y+1,img,srccolor,color,m,n);
        fill(x+1,y,img,srccolor,color,m,n);
        fill(x-1,y,img,srccolor,color,m,n);
        fill(x,y-1,img,srccolor,color,m,n);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
          fill(sr,sc,image,image[sr][sc],color,image.size(),image[0].size());
            return image;
    }
};