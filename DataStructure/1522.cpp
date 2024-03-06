//
//  1522.cpp
//  DataStructure
//
//  Created by 김채은 on 2024/03/06.
//

#include <iostream>
using namespace std;

int main() {
    string s;
    cin >> s;
    
    int len = 0;
    for(int i = 0; i < s.length(); i++) {
        if(s[i] == 'a') len++;
    }
    
    int res = 1000000000;
    int cnt = 0;
    for(int i = 0; i < s.length(); i++) {
        for(int j = i; j < i + len; j++) {
            if(s[j % s.length()] == 'b') cnt++;
        }
        res = min(res, cnt);
        cnt = 0;
    }
    
    cout << res;
}
