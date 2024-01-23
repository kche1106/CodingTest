//
//  15903.cpp
//  DataStructure
//
//  Created by 김채은 on 2024/01/22.
//

#include <iostream>
#include <queue>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    priority_queue<long long> pq;
    for(int i = 0; i < n; i++){
        int num;
        cin >> num;
        pq.push(-num);
    }
    
    while(m--) {
        long long n1 = -pq.top();
        pq.pop();
        long long n2 = -pq.top();
        pq.pop();
        
        long long sum = n1 + n2;
        pq.push(-sum);
        pq.push(-sum);
    }
    
    long long res = 0;
    for(int i = 0; i < n; i++) {
        res += -(pq.top());
        pq.pop();
    }
    
    cout << res << endl;
    
}
