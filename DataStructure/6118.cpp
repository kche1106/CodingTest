//
//  6118.cpp
//  DataStructure
//
//  Created by 김채은 on 2024/02/12.
//

#include <iostream>
#include <queue>
using namespace std;

int visited[20001];
int dist[20001];

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<int> map[50001];
    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        map[a].push_back(b);
        map[b].push_back(a);
    }
    
    queue<int> q;
    q.push(1);
    visited[1] = 1;
    
    while(!q.empty()) {
        int x = q.front();
        q.pop();
        
        for(int i = 0; i < map[x].size(); i++) {
            int nx = map[x][i];
            if(visited[nx] == 0) {
                visited[nx] = 1;
                q.push(nx);
                dist[nx] = dist[x] + 1;
            }
        }
    }
    
    int far = 0;
    int idx = 0;
    for(int i = 1; i <= n; i++) {
        if(dist[i] > far) {
            far = dist[i];
            idx = i;
        }
    }
    
    int cnt = 0;
    for(int i = 1; i <= n; i++) {
        if(dist[i] == far) cnt++;
    }
    
    cout << idx << " " << far << " " << cnt;
}
