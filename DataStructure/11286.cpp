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
    
    priority_queue<int, vector<int>, comp> pq;
    
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        
        if(x == 0) {
            if(pq.empty()) cout << "0\n";
            else {
                cout << pq.top() << '\n';
                pq.pop();
            }
        }
        else {
            pq.push(x);
        }
    }
}
