//
//  12919.cpp
//  DataStructure
//
//  Created by 김채은 on 2024/02/26.
//

#include <iostream>
#include <algorithm>
using namespace std;

string s, t;
bool ans = false;

void func(string tmp) {
//    cout << tmp << endl;
    if(tmp == s) {
        cout << "1";
        exit(0);
    }
    
    if(tmp.back() == 'A') {
        string tmp2 = tmp;
        tmp2.pop_back();
        func(tmp2);
    }
    if(tmp.front() == 'B') {
        string tmp2 = tmp.substr(1, tmp.size());
        reverse(tmp2.begin(), tmp2.end());
        func(tmp2);
    }
}

int main() {
    cin >> s >> t;
    func(t);
    
    cout << 0;
}
