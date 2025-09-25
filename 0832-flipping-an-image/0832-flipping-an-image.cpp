class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        int m = image.size();
        int n = image[0].size();// m rows  &   n cols
        for(int i=0;i<m;i++){
            for(int j=0;j<n/2;j++){
                int k = image[i][j];
                image[i][j] = image[i][n-1-j];
                image[i][n-1-j] = k;
            }
            for(int j=0;j<n;j++)
                image[i][j]^=1;
        } 
        return image;
    }
};