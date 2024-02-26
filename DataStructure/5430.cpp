//
//  5430.cpp
//  DataStructure
//
//  Created by 김채은 on 2024/02/25.
//

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <deque>
using namespace std;

int main() {
    int t;
    cin >> t;
    
    while(t--) {
        string p;
        cin >> p;
        
        vector<char> command;
        for(int i = 0; i < p.length(); i++) {
            command.push_back(p[i]);
        }
        
        int n;
        cin >> n;
        
        string arr;
        cin >> arr;
        
        char c[arr.length()-2];  //[,] 제거한 문자 저장
        for(int i = 1; i < arr.length()-1; i++) {
            c[i-1] = arr[i];
        }
        
        string ss(c);
        stringstream sstream(ss);
        string token;
        
        deque<int> num;
        while(getline(sstream, token, ',')) {  //, 제거한 숫자 저장
            num.push_back(stoi(token));
        }
        
        bool tmp = true;
        bool rev = false;
        for(int i = 0; i < command.size(); i++) {
            if(command[i] == 'R') {
                if(rev) rev = false;
                else rev = true;
            }
            else if(command[i] == 'D') {
                if(num.empty()) {
                    cout << "error" << endl;
                    tmp = false;
                    break;
                }
                if(rev) num.pop_back();
                else num.pop_front();
            }
        }
        
        if(tmp) {
            cout << "[";
            if(!rev) {  //뒤집힌 상태가 아니라면
                for(int i = 0; i < num.size(); i++) {
                    if(i == num.size()-1) cout << num[i];
                    else cout << num[i] << ",";
                }
            }
            else {  //뒤집힌 상태
                for(int i = num.size()-1; i >= 0; i--) {
                    if(i == 0) cout << num[i];
                    else cout << num[i] << ",";
                }
            }
            cout << "]" << endl;
        }
    }
}
