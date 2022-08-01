//
//  11866.cpp
//  DataStructure
//
//  Created by 김채은 on 2022/07/24.
//

#include<iostream>
#include<queue>
using namespace std;

int main()
{
    
    queue<int> q;
        
    int n, k;
    cin >> n;
    cin >> k;

    for(int i = 1; i <= n; i++) {
        q.push(i);
    }
    
    cout << "<";
    
    while (!q.empty()) {
        
        for(int i = 1; i <= k - 1; i++) {
            q.push(q.front());
            q.pop();
        }
        
        cout << q.front();
        
        if (q.size() != 1) {
            cout << ", ";
        }
        q.pop();
    }
    cout << ">";
}
