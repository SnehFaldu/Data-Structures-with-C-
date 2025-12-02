// DSC_078_question.cpp
// 78. Find the first circular tour that visits all Petrol Pumps (gas station problem)

#include <bits/stdc++.h>
using namespace std;
// petrol[i] = petrol gained, dist[i] = distance to next
int canComplete(vector<int>& petrol, vector<int>& dist){
    int n=petrol.size(), start=0, deficit=0, balance=0;
    for(int i=0;i<n;i++){
        balance += petrol[i]-dist[i];
        if(balance<0){ deficit += balance; start = i+1; balance = 0; }
    }
    return (balance+deficit>=0) ? start : -1;
}
int main(){
    vector<int> petrol{4,6,7,4}, dist{6,5,3,5};
    cout<<canComplete(petrol, dist)<<"\n"; // 1
    return 0;
}
