#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int sqr(int x){
        return x*x;
    }
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        int x=max(x1,min(x2,xCenter));
        int y=max(y1,min(y2,yCenter));
        if(sqr(x-xCenter)+sqr(y-yCenter)<=sqr(radius)){
            return true;
        }
        return false;
        // for(int i=x1;i<=x2;i++){
        //     for(int j=y1;j<=y2;j++){
        //         int c1=i-xCenter;
        //         int c2=j-yCenter;
        //         if(c1*c1+c2*c2<=radius*radius){
        //             return true;
        //         }
        //     }
        // }
        // return false;
    }
};