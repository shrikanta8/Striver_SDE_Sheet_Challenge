class Solution {
public:
    void paint(vector<vector<int>>& image, int x, int y,int r, int c, int newColor, int oldColor){
        if(x<0 || y<0 || x>=r|| y>=c ||  image[x][y] != oldColor) return;
        
        image[x][y] = newColor;
        
        paint(image,x+1,y,r,c,newColor,oldColor);
        paint(image,x-1,y,r,c,newColor,oldColor);
        paint(image,x,y+1,r,c,newColor,oldColor);
        paint(image,x,y-1,r,c,newColor,oldColor);
        
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        
        if( image[sr][sc]== newColor) 
            return image;
        int c=image[0].size() ,r=image.size();
        int oldColor = image[sr][sc];
        paint(image,sr,sc,r,c,newColor,oldColor);
        return image;
    }
};
