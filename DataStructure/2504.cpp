//
//  2504.cpp
//  DataStructure
//
//  Created by 김채은 on 2023/12/18.
//

#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
    string s;
    cin >> s;
    
    int res = 0, tmp = 1;
    stack<char> st;
    for(int i = 0; i < s.length(); i++) {
        char c = s[i];
//        char pre = s[i-1];
        
        if(c == '(') {
            st.push(c);
            tmp *= 2;
        }
        
        if(c == '[') {
            st.push(c);
            tmp *= 3;
        }
        
        if(c == ')') {
            if(st.empty() || st.top() == '[') {
                res = 0;
                break;
            }
            
            if(s[i-1] == '(') {  //()짝이 바로 찾아졌을 때
                st.pop();
                res += tmp;
                tmp /= 2;
            }
            
            else {  //()짝 안에 여러 식이 있었을 때
                tmp /= 2;
                st.pop();
            }
        }
        
        if(c == ']') {
            if(st.empty() || st.top() == '(') {
                res = 0;
                break;
            }
            
            if(s[i-1] == '[') {  //[]짝이 바로 찾아졌을 때
                st.pop();
                res += tmp;
                tmp /= 3;
            }
            
            else {  //[]짝 안에 여러 식이 있었을 때
                tmp /= 3;
                st.pop();
            }
        }
    }
    
    if(st.empty()) cout << res << '\n';
    else cout << "0\n";
}
