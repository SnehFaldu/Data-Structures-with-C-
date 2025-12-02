// DSC_092_question.cpp
// 92. Print all the permutations of the given string

#include <bits/stdc++.h>
using namespace std;
int main(){
    string s="abc";
    sort(s.begin(), s.end());
    do { cout<<s<<"\n"; } while(next_permutation(s.begin(), s.end()));
}
