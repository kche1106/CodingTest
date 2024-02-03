//
//  1697.cpp
//  DataStructure
//
//  Created by 김채은 on 2024/02/03.
//

#include <iostream>
#include <queue>
using namespace std;

int visited[100000];
int dist[100000];

int main() {
    int n, k;
    cin >> n >> k;
    
    queue<int> q;
    q.push(n);
    visited[n] = 1;
    
    while(!q.empty()) {
        int x = q.front();
        q.pop();
        
        if(x == k) {
            cout << dist[k] << endl;
            break;
        }
        
        int nx = 0;
        for(int i = 0; i < 3; i++) {
            if(i == 0) nx = x - 1;
            else if(i == 1) nx = x + 1;
            else if(i == 2) nx = x * 2;
            
            if(nx < 0 || nx > 100000) continue;
            
            if(visited[nx] == 0) {
                q.push(nx);
                visited[nx] = 1;
                dist[nx] = dist[x] + 1;
            }
        }
    }
}
