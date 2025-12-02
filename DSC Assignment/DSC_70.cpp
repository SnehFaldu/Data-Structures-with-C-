// DSC_070_question.cpp
// 70. Stack Permutations (Check if an array is stack permutation of other)

#include <bits/stdc++.h>
using namespace std;
bool isStackPermutation(vector<int> a, vector<int> b){
    stack<int> st; int i=0;
    for(int x: a){
        st.push(x);
        while(!st.empty() && st.top()==b[i]){ st.pop(); i++; if(i==b.size()) break; }
    }
    return i==b.size();
}
int main(){
    cout<<(isStackPermutation({1,2,3},{2,1,3}) ? "Yes\n" : "No\n");
    return 0;
}
