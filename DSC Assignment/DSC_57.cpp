// DSC_057_question.cpp
// 57. Find the next Greater element for each element in an array.

#include <bits/stdc++.h>
using namespace std;
vector<int> nextGreater(const vector<int>& a){
    int n=a.size();
    vector<int> res(n, -1);
    stack<int> st; // indices with decreasing values
    for(int i=0;i<n;i++){
        while(!st.empty() && a[i] > a[st.top()]){
            res[st.top()] = a[i]; st.pop();
        }
        st.push(i);
    }
    return res;
}
int main(){
    vector<int> a = {4,5,2,25};
    auto r = nextGreater(a);
    for(int x: r) cout<<x<<" ";
    cout<<"\n";
    return 0;
}
