//
//  1406.cpp
//  DataStructure
//
//  Created by 김채은 on 2024/03/04.
//

#include <iostream>
#include <stack>
using namespace std;

int main() {
    string s;
    cin >> s;
    
    stack<char> st_org;
    stack<char> st_tmp;
    for(int i = 0; i < s.length(); i++) {
        st_org.push(s[i]);
    }
    
    int m;
    cin >> m;
    
    for(int i = 0; i < m; i++) {
        char command;
        cin >> command;
        
        if(command == 'P') {
            char in;
            cin >> in;
            
            st_org.push(in);
        }
        
        else if(command == 'L') {
            if(!st_org.empty()) {
                st_tmp.push(st_org.top());
                st_org.pop();
            }
        }
        
        else if(command == 'D') {
            if(!st_tmp.empty()) {
                st_org.push(st_tmp.top());
                st_tmp.pop();
            }
        }
        
        else if(command == 'B') {
            if(!st_org.empty()) st_org.pop();
        }
    }
    
    while(!st_org.empty()) {
        st_tmp.push(st_org.top());
        st_org.pop();
    }
    
    while(!st_tmp.empty()) {
        cout << st_tmp.top();
        st_tmp.pop();
    }
    
}
