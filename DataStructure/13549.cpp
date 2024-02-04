//
//  13549.cpp
//  DataStructure
//
//  Created by 김채은 on 2024/02/04.
//

#include <iostream>
#include <deque>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    
    int visited[100001] = {0, };
    int dist[100001] = {0, };
    deque<int> q;
    q.push_back(n);
    visited[n] = 1;
    
    while(!q.empty()) {
        int x = q.front();
        q.pop_front();
        
        if(x == k) {
            cout << dist[x] << endl;
            break;
        }
        
        int nx = 0;
        for(int i = 0; i < 3; i++) {
            if(i == 0) nx = x * 2;
            else if(i == 1) nx = x - 1;
            else if(i == 2) nx = x + 1;
            
            if(nx < 0 || nx > 100000) continue;
            if(visited[nx] == 0) {
                visited[nx] = 1;
                if(i == 0) {
                    q.push_front(nx);
                    dist[nx] = dist[x];
                }
                else {
                    q.push_back(nx);
                    dist[nx] = dist[x] + 1;
                }
            }
        }
    }
}
