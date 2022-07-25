//
//  18258.cpp
//  DataStructure
//
//  Created by 김채은 on 2022/07/24.
//

#include <iostream>
#include <queue>
using namespace std;

int main() {
    
    queue<int> q;
    
    int N;
    cin >> N;
    
    string s;
    for(int i = 0; i < N; i++) {
        cin >> s;
        if(s == "push") {
            int n;
            cin >> n;
            q.push(n);
        }
        
        else if(s == "pop") {
            if(q.empty()) cout << "-1" << endl;
            else cout << q.front() << endl;
            q.pop();
        }
        
        else if(s == "size") {
            cout << q.size() << endl;
        }
        
        else if(s == "empty") {
            cout << q.empty() << endl;
        }
        
        else if(s == "front") {
            if(q.empty()) cout << "-1" << endl;
            else cout << q.front() << endl;
        }
        
        else if(s == "back") {
            if(q.empty()) cout << "-1" << endl;
            else cout << q.back() << endl;
        }
    }
}


