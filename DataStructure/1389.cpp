//
//  1389.cpp
//  DataStructure
//
//  Created by 김채은 on 2024/02/12.
//

#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

vector<int> friends[101];
int visited[101];
int dist[101][101];

void BFS(int s) {
    queue<int> q;
    q.push(s);
    memset(visited, 0, sizeof(visited));
    visited[s] = 1;
    
    while(!q.empty()) {
        int x = q.front();
        q.pop();
        
        for(int i = 0; i < friends[x].size(); i++) {
            int nx = friends[x][i];
            
            if(visited[nx] == 0) {
                visited[nx] = 1;
                q.push(nx);
                dist[s][nx] = dist[s][x] + 1;
                dist[nx][s] = dist[x][s] + 1;
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    
    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        friends[a].push_back(b);
        friends[b].push_back(a);
    }
    
    for(int i = 1; i <= n; i++) {
        BFS(i);
    }
    
    int ans = 100000;
    int idx = 0;
    for(int i = 1; i <= n; i++) {
        int sum = 0;
        for(int j = 1; j <= n; j++) {
            sum += dist[i][j];
        }
        if(ans > sum) {
            ans = sum;
            idx = i;
        }
    }
    
    cout << idx;
}
