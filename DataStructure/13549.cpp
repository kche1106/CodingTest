//
//  13549.cpp
//  DataStructure
//
//  Created by 김채은 on 2024/02/04.
//

#include <iostream>
#include <queue>
using namespace std;

int visited[100001];
int dist[100001];

int main() {
    int n, k;
    cin >> n >> k;
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;

    q.push({0, n});
    visited[n] = 1;
    
    while (!q.empty()) {
        int x = q.top().second;
        q.pop();
        
        if(x == k) {
            cout << dist[x];
            break;
        }
        
        int nx = 0;
        for(int i = 0; i < 3; i++) {
            if(i == 0) nx = x * 2;
            else if(i == 1) nx = x + 1;
            else nx = x - 1;
            
            if(nx < 0 || nx > 100000) continue;
            
            if(visited[nx] == 0) {
                visited[nx] = 1;
                if(i == 0) dist[nx] = dist[x];
                else dist[nx] = dist[x] + 1;
                q.push({dist[nx], nx});
            }
        }
    }
}
