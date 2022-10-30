// https://leetcode.com/problems/flood-fill/
#include<bits/stdc++.h>
using namespace std;

bool isValid(vector<vector<int>>& image, int i, int j, int n, int m, int color, int newColor) {
    if(i >= 0 && i < n && j >= 0 && j < m && image[i][j] == color)
        return true;
    return false;
}
    
void floodFillRec(vector<vector<int>>& image, int i, int j, int n, int m, int color, int newColor) {
    image[i][j] = newColor;
    
    if(isValid(image, i+1, j, n, m, color, newColor))
        floodFillRec(image, i+1, j, n, m, color, newColor);
    
    if(isValid(image, i-1, j, n, m, color, newColor))
        floodFillRec(image, i-1, j, n, m, color, newColor);
    
    if(isValid(image, i, j+1, n, m, color, newColor))
        floodFillRec(image, i, j+1, n, m, color, newColor);
    
    if(isValid(image, i, j-1, n, m, color, newColor))
        floodFillRec(image, i, j-1, n, m, color, newColor);
}

vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
    
    int n = image.size();
    int m = image[0].size();
    
    int color = image[sr][sc];
    
    if(color == newColor)
        return image;
    
    floodFillRec(image, sr, sc, n, m, color, newColor);
    
    return image;
    
}

int main() {
    vector<vector<int> > image = {
        {1, 1, 1},
        {1, 1, 0},
        {1, 0, 1}
    };
    
    // starting index
    int sr = 1;
    int sc = 1;
    
    // new color to fill
    int newColor = 2;
    
    vector<vector<int> > ans = floodFill(image, sr, sc, newColor);
    
    cout<<"Flodd fill algo: "<<endl;
    for(int i=0; i<ans.size(); i++) {
        for(int j=0; j<ans.size(); j++) {
            cout<<ans[i][j]<<" ";
        }cout<<endl;
    }
    
    return 0;
}