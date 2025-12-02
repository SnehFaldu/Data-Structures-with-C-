// DSC_096_question.cpp
// 96. Find next greater number with same set of digits (next permutation)

#include <bits/stdc++.h>
using namespace std;
long long nextGreaterNumber(long long num){
    string s = to_string(num);
    if(next_permutation(s.begin(), s.end())) return stoll(s);
    return -1; // no greater permutation
}
int main(){ cout<<nextGreaterNumber(218765)<<"\n"; } // 251678
