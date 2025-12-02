// DSC_086_question.cpp
// 86. Next Smaller Element (for each element find next smaller to its right)

#include <bits/stdc++.h>
using namespace std;
vector<int> nextSmaller(const vector<int>& a){
    int n=a.size(); vector<int> res(n, -1);
    stack<int> st;
    for(int i=0;i<n;++i){
        while(!st.empty() && a[i] < a[st.top()]){
            res[st.top()] = a[i]; st.pop();
        }
        st.push(i);
    }
    return res;
}

int main(){
    for(int x: nextSmaller({4,5,2,10,8})) cout<<x<<" ";
    cout<<"\n";
}
