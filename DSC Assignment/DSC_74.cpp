// DSC_074_question.cpp
// 74. LRU Cache Implementation (using list + unordered_map)

#include <bits/stdc++.h>
using namespace std;
struct LRUCache {
    int cap;
    list<pair<int,int>> ls;
    unordered_map<int, list<pair<int,int>>::iterator> mp;
    LRUCache(int c):cap(c){}
    int get(int k){
        if(mp.find(k)==mp.end()) return -1;
        auto it = mp[k];
        int val = it->second;
        ls.erase(it);
        ls.emplace_front(k,val);
        mp[k] = ls.begin();
        return val;
    }
    void put(int k,int v){
        if(mp.find(k)!=mp.end()){ ls.erase(mp[k]); mp.erase(k); }
        if(ls.size()==cap){ auto last = ls.back(); mp.erase(last.first); ls.pop_back(); }
        ls.emplace_front(k,v); mp[k]=ls.begin();
    }
};
int main(){
    LRUCache c(2);
    c.put(1,1); c.put(2,2); cout<<c.get(1)<<"\n"; c.put(3,3); cout<<c.get(2)<<"\n"; // -1
    return 0;
}
