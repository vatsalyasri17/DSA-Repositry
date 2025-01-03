#include<bits/stdc++.h>
using namespace std;
// The number of "bulls", which are digits in the guess that are in the correct position.
// The number of "cows", which are digits in the guess that are in your secret number but are located in the wrong position. Specifically, the non-bull digits in the guess that could be rearranged such that they become bulls.Return Hint in form of xAyB

class Solution {
public:
    string getHint(string secret, string guess) {
        vector<int>Sec(10,0);
        vector<int>Guess(10,0);
        int cntA=0,cntB=0;
        for(int i=0;i<secret.size();i++){
            if(secret.size()!=guess.size()) return "0A0B";
            int a=secret[i];
            int b=guess[i];
            if(a==b){
                cntA++;
            }
            else{
                Sec[secret[i]-'0']++;
                Guess[guess[i]-'0']++;
            }
        }
        for(int i=0;i<Sec.size();i++){
            cntB+=min(Sec[i],Guess[i]);
        }
        return to_string(cntA) + "A" + to_string(cntB) + "B";
    }
};