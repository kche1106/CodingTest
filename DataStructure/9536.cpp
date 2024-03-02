//
//  9536.cpp
//  DataStructure
//
//  Created by 김채은 on 2024/03/02.
//

#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main() {
    int t;
    cin >> t;
    
    while(t--) {
        
        string s;
        vector<string> v;  //녹음된 소리
        map<string, string> m;  //동물 울음소리
        
        while(true) {
            cin >> s;
            if(s == "what") break;
            v.push_back(s);
        }
        
        for(int i = 0; i < v.size(); i++) {
            if(v[i] == "goes") m.insert({v[i+1], v[i-1]});
        }
        
        int idx = 0;
        for(int i = v.size(); i >= 0; i--) {
            if(v[i] == "goes") idx = i-1;
        }
        v.erase(v.begin() + idx, v.end());
        
        for(int i = 0; i < 4; i++) cin >> s;
        
        vector<string> ans;
        for(int i = 0; i < v.size(); i++) {
            auto search = m.find(v[i]);
            if(search == m.end()) ans.push_back(v[i]);
        }
        
        for(int i = 0; i < ans.size(); i++)
            cout << ans[i] << " ";
    }
}
