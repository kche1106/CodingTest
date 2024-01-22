//
//  15903.cpp
//  DataStructure
//
//  Created by 김채은 on 2024/01/22.
//

#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    
    priority_queue<long long> pq;
    for(int i = 0; i < n; i++) {
        long long num;
        cin >> num;
        pq.push(-num);
    }
    
    for(int i = 0; i < m; i++) {
        long long first = -pq.top();
        pq.pop();
        long long second = -pq.top();
        pq.pop();
        long long sum = first + second;
        
        pq.push(-sum);
        pq.push(-sum);
    }
    
    long long res = 0;
    for(int i = 0; i < n; i++) {
        res += (-pq.top());
        pq.pop();
    }
    
    cout << res << endl;
}
