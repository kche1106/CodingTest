//
//  1874.cpp
//  DataStructure
//
//  Created by 김채은 on 2024/02/19.
//

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    stack<int> s;
    vector<char> path;
    
    int cnt = 1;
    for(int i = 1; i <= n; i++) {
        int x;  //수열 원소
        cin >> x;
        
        while(cnt <= x) {
            path.push_back('+');
            s.push(cnt);
            cnt++;
        }
        
        if(s.top() == x) {
            path.push_back('-');
            s.pop();
        }
        else {
            cout << "NO";
            return 0;
        }
    }

    for(int i = 0; i < path.size(); i++) {
        cout << path[i] << '\n';
    }
        
}
