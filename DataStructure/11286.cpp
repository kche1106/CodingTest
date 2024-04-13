//
//  11286.cpp
//  DataStructure
//
//  Created by 김채은 on 2024/02/19.
//

#include <iostream>
#include <queue>
#include <cmath>
using namespace std;

//https://my-codinglog.tistory.com/21

struct comp {
    bool operator() (int a, int b) {
        if(abs(a) == abs(b)) {
            return a > b;
        }
        else return abs(a) > abs(b);
    }
};

int main() {
    int n;
    cin >> n;
    
    priority_queue<int, vector<int>, comp> q;
    
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        
        if(x == 0) {
            if(q.empty()) cout << "0\n";
            else {
                cout << q.top() << '\n';
                q.pop();
            }
        }
        else {
            q.push(x);
        }
    }
}
