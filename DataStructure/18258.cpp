//
//  18258.cpp
//  DataStructure
//
//  Created by 김채은 on 2022/07/24.
//

#include <iostream>
#include <queue>
#include <string>
using namespace std;

int main() {
    
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
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
            if(q.empty()) cout << "-1" << '\n';
            else {
                cout << q.front() << '\n';
                q.pop();
            }
        }
        
        else if(s == "size") {
            cout << q.size() << '\n';
        }
        
        else if(s == "empty") {
            if (q.empty()) cout << "1" << '\n';
            else cout << "0" << "\n";
        }
        
        else if(s == "front") {
            if(q.empty()) cout << "-1" << '\n';
            else cout << q.front() << '\n';
        }
        
        else if(s == "back") {
            if(q.empty()) cout << "-1" << '\n';
            else cout << q.back() << '\n';
        }
    }
}


