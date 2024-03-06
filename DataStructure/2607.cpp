//
//  2607.cpp
//  DataStructure
//
//  Created by 김채은 on 2024/03/04.
//

#include <iostream>
#include <map>
using namespace std;

string word;
map<char, int> alpha;
int res;

void func(string cmp, map<char, int> m) {
    int cnt = 0;
    for(int i = 0; i < cmp.length(); i++) {  //cmp 길이가 더 길 경우
        char c = cmp[i];
        if(m[c] > 0) m[c]--;  //겹치는 글자
        else cnt++;  //안겹침
    }
    if(cnt > 1) return;
    
    int cnt2 = 0;
    for(auto i = m.begin(); i != m.end(); i++) {
        if(m[i->first] > 0) cnt2++;   //cmp 길이가 더 짧을 경우
    }
    if(cnt2 > 1) return;  //1글자 넘게 차이나면 유사 X
    
    res++;
}

int main() {
    int n;
    cin >> n;
    
    cin >> word;
    for(int i = 0; i < word.length(); i++) {
        alpha[word[i]]++;
    }
    
    map<char, int> m;
    for(int i = 0; i < n-1; i++) {
        string w;
        cin >> w;
        
        m = alpha;
        func(w, m);
    }
    
    cout << res;
}
