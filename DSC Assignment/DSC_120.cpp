// DSC_120_question.cpp
// 120. Word Ladder (transform beginWord to endWord using dictionary words, BFS)

#include <bits/stdc++.h>
using namespace std;
int ladderLength(string beginWord, string endWord, vector<string>& wordList){
    unordered_set<string> dict(wordList.begin(), wordList.end());
    if(!dict.count(endWord)) return 0;
    queue<pair<string,int>> q; q.push({beginWord,1});
    while(!q.empty()){
        auto [word, dist] = q.front(); q.pop();
        if(word==endWord) return dist;
        for(int i=0;i<word.size();++i){
            char orig = word[i];
            for(char c='a'; c<='z'; ++c){
                if(c==orig) continue;
                word[i]=c;
                if(dict.count(word)){
                    dict.erase(word);
                    q.push({word, dist+1});
                }
            }
            word[i]=orig;
        }
    }
    return 0;
}
int main(){
    vector<string> dict{"hot","dot","dog","lot","log","cog"};
    cout<<ladderLength("hit","cog", dict)<<"\n"; // 5
}
