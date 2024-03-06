//
//  2075.cpp
//  DataStructure
//
//  Created by 김채은 on 2024/03/04.
//

#include <iostream>
#include <queue>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin >> n;
    
    priority_queue<int, vector<int>, greater<int>> q;
    int num;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> num;
            q.push(num);
            if(q.size() > n) q.pop();
        }
    }
    cout << q.top();
}
