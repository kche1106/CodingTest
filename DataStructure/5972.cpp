//
//  5972.cpp
//  DataStructure
//
//  Created by 김채은 on 2024/03/11.
//

#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;

int n, m;
vector<pair<int, int>> map[50001];
int dist[50001];

void bfs() {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({1, 0});
    fill(dist, dist+n+1, 1e9+10);
    dist[1] = 0;
    
    while(!pq.empty()) {
        int x = pq.top().first;
        int c = pq.top().second;
        pq.pop();
        
        for(int i = 0; i < map[x].size(); i++) {
            int nx = map[x][i].first;
            int nc = map[x][i].second;
                                                
            if(dist[nx] > dist[x] + nc) {
                dist[nx] = dist[x] + nc;
                pq.push({nx, nc});
//                cout << "x = " << x << " nx = " << nx << " d = " << dist[nx] << "\n";
            }
        }
    }
}

int main() {
    cin >> n >> m;
    
    for(int i = 0; i < m; i++) {
        int a, b, c;  //출발, 도착, 소
        cin >> a >> b >> c;
        map[a].push_back({b, c});
        map[b].push_back({a, c});
    }
    
    bfs();
    
    cout << dist[n];
}
