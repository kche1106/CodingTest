//
//  9935.cpp
//  DataStructure
//
//  Created by 김채은 on 2024/02/25.
//

#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    cin >> s;
    
    string bomb;
    cin >> bomb;
    
    string tmp = "";
    for(int i = 0; i < s.length(); i++) {
        tmp += s[i];
        
        if(tmp.back() == bomb.back() && tmp.size() >= bomb.size()) {
            int tmp_idx = tmp.size() - 1;  //뒤에서부터 확인
            bool check = true;
            
            for(int j = bomb.size()-1; j >= 0; j--) {
                if(bomb[j] != tmp[tmp_idx]) {
                    check = false;
                    break;
                }
                tmp_idx--;
            }
            if(check) {  //bomb와 일치하면
                for(int i = 0; i < bomb.size(); i++)
                    tmp.pop_back();
            }
        }
    }
    
    if(tmp.empty()) cout << "FRULA\n";
    else cout << tmp << "\n";
}
