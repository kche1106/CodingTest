//
//  12904.cpp
//  DataStructure
//
//  Created by 김채은 on 2024/02/25.
//

#include <iostream>
#include <algorithm>
using namespace std;

string s, t;
bool res;

//void dfs(string str) {
//    if(str.length() > t.length()) return;
//    if(str == t) {
//        res = true;
//        return;
//    }
//    
//    dfs(str + 'A');
//    reverse(str.begin(), str.end());
//    dfs(str + 'B');
//}

int main() {
    cin >> s >> t;
    
    while(true) {
        if(s.length() == t.length()) {
            if(s == t) res = true;
            else res = false;
            break;
        }
        
        if(t.back() == 'A') t.pop_back();
        else {
            t.pop_back();
            reverse(t.begin(), t.end());
        }
    }
    
    cout << res;
}
