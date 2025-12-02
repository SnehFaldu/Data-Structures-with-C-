// DSC_032_question.cpp
// 32. Search an element in a matrix (row & column wise sorted)
// (Repeat; included earlier. Keep for completeness.)

#include <bits/stdc++.h>
using namespace std;
int main() {
    vector<vector<int>> a = {{1,4,7},{2,5,9},{3,6,12}};
    int target = 5;
    int i=0, j=a[0].size()-1;
    bool found=false;
    while(i < (int)a.size() && j>=0){
        if (a[i][j]==target){ cout<<"Found at "<<i<<","<<j<<"\n"; found=true; break; }
        else if (a[i][j] > target) --j;
        else ++i;
    }
    if(!found) cout<<"Not found\n";
    return 0;
}
