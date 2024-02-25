//
//  swm.cpp
//  DataStructure
//
//  Created by 김채은 on 2024/02/24.
//

#include <iostream>
#include <deque>
#include <queue>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    int vals[1001];
    for(int i = 0; i < n; i++) {
        cin >> vals[i];
    }
    
    deque<int> dq[1001];
    priority_queue<int> pq;
    for(int i = 0; i < n; i++) {
        int mod = vals[i] % n;
        dq[mod].push_back(vals[i]);
    }
    
    for(int i = 0; i < n; i++) {
        int empty = 0;
        for(int j = i-1; j >= 0; j--) {
            if(dq[j].empty()) empty++;
        }
        
        while(dq[i].size() > 1) {
            
            if(empty == 0) {
                pq.push(dq[i].back());
                dq[i].pop_back();
            }
            else if(empty < i) {
                pq.push(dq[i].front());
                dq[i].pop_front();
            }
            else {
                
            }
        }
    }
    
    for(int i = n-1; i >= 0; i--) {
        if(dq[i].size() == 0) {
            dq[i].push_back(pq.top());
            pq.pop();
        }
    }
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < dq[i].size(); j++) {
            cout << dq[i].front() << " ";
        }
        cout << endl;
    }
}

/*
7 2 5 6 13 14 16 35
10 1 2 11 21 26 35 37 58 98 105
 */
