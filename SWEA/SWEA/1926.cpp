//
//  1926.cpp
//  SWEA
//
//  Created by 김채은 on 2023/10/31.
//

#include <iostream>
#include <string>
using namespace std;

int main() {
    int N;
    cin >> N;
    
    for(int i = 1; i <= N; i++) {
        string s = to_string(i);
        
        bool check = true;
        int cnt = 0;
        
        for(int j = 0; j < s.size(); j++) {
            if(s[j] == '3' || s[j] == '6' || s[j] == '9') {
                cnt ++;
                check = false;
            }
        }
        
        if(check) cout << i << " ";
        else {
            for(int k = 0; k < cnt; k++)
                cout << "-";
            cout << " ";
        }
    }
}
