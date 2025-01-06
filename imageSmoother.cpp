#include<bits/stdc++.h>
using namespace std;
// You have a grid filled with numbers, which we will call an "image". You are asked to create a new image where the value of each cell is the average of itself and its neighbors. However, if a cell doesn't have a neighbor in any direction (because it's on the edge), just ignore that non-existing neighbor when computing the average.

// For instance, the cell at the top left corner has only three neighbors (right, down-right, down), while a cell in the middle of the image has eight neighbors (up, down, left, right, and all the four diagonals).

// The goal is to create a new image with these averaged values. Round down the average if it's not an integer.
class Solution {
public:
    int smoothen(vector<vector<int>>&img,int x,int y){
        int m=img.size();
        int n=img[0].size();
        int sum=0,cnt=0;
        for(int i=-1;i<=+1;i++){
            for(int j=-1;j<=+1;j++){
                int nx=i+x;
                int ny=j+y;
                if(nx>=0 && nx<m && ny>=0 && ny<n){
                    sum+=img[nx][ny];
                    cnt++;
                }
            }
        }
        return sum/cnt;
    }
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int m=img.size();
        int n=img[0].size();
        vector<vector<int>>image(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                image[i][j]=smoothen(img,i,j);
            }
        }
        return image;
    }
};