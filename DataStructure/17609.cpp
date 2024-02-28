//
//  17609.cpp
//  DataStructure
//
//  Created by 김채은 on 2024/02/28.
//

#include <iostream>
using namespace std;

string s;
int cnt;

bool palindrome(int front, int end) {  //cnt는 지운 횟수
    while(front < end) {
        if(s[front] != s[end]) {
            if(cnt >= 1) return false;
            else if(cnt == 0) {
                cnt++;
                return (palindrome(front+1, end)|| palindrome(front, end-1));
            }
        }
        else {  //앞과 뒤 문자가 동일
            front++;
            end--;
        }
    }
    return true;
}

int main() {
    int t;
    cin >> t;
    
    while(t--) {
        cin >> s;
        
        bool res = palindrome(0, s.length()-1);
        if(res) {
            if(cnt == 0) cout << "0" << endl;
            else cout << "1" << endl;
        }
        else cout << "2" << endl;
        
        s = "";
        cnt = 0;
    }
}
