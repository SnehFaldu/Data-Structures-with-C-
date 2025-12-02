// DSC_065_question.cpp
// 65. Largest rectangular Area in Histogram

#include <bits/stdc++.h>
using namespace std;
int largestRectangle(vector<int>& h){
    stack<int> st; int n=h.size(), best=0;
    for(int i=0;i<=n;i++){
        int cur = (i==n?0:h[i]);
        while(!st.empty() && cur < h[st.top()]){
            int height = h[st.top()]; st.pop();
            int left = st.empty()?0:st.top()+1;
            best = max(best, height * (i - left));
        }
        st.push(i);
    }
    return best;
}
int main(){
    vector<int> h{2,1,5,6,2,3};
    cout<<largestRectangle(h)<<"\n"; // 10
    return 0;
}
