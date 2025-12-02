// DSC_107_question.cpp
// 107. Minimum number of swaps for bracket balancing (only '[' and ']')

#include <bits/stdc++.h>
using namespace std;
int minSwapsToBalance(string s){
    int open=0, swaps=0, imbalance=0;
    for(char c: s){
        if(c=='['){ open++; if(imbalance>0){ swaps += imbalance; imbalance = max(0, imbalance-1); } }
        else { // ']'
            if(open>0) open--; else imbalance++;
        }
    }
    return swaps;
}
int main(){ cout<<minSwapsToBalance("][][")<<"\n"; } // 1
