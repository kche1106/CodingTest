//
//  20310.cpp
//  DataStructure
//
//  Created by 김채은 on 2024/03/24.
//

#include <iostream>
using namespace std;

int main() {
    string s;
    cin >> s;
    
    int zero = 0;
    int one = 0;
    for(int i = 0; i < s.length(); i++) {
        if(s[i] == '0') zero++;
        else one++;
    }
    
    int zero_cnt = 0;
    int one_cnt = 0;
    string ans = "";
    for(int i = 0; i < s.length(); i++) {
        if(s[i] == '0') {
            if(zero_cnt < zero/2) {
                zero_cnt++;
                ans += s[i];
            }
        }
        else if(s[i] == '1') {
            if(one_cnt < one/2) {
                one_cnt++;
                continue;
            }
            else ans += s[i];
        }
    }
    
    cout << ans;
}
