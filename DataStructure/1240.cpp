//
//  1240.cpp
//  DataStructure
//
//  Created by 김채은 on 2024/02/11.
//

#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int n, m;
vector<pair<int, int>> map[1001];
queue<int> q;
int visited[1001];
int res;

void BFS(int start, int dest) {
    queue<pair<int, int>> q;
    q.push({start, 0});
    visited[start] = 1;
    res = 0;
    
    while(!q.empty()) {
        int x = q.front().first;
        int dist = q.front().second;
        q.pop();
        
        if(x == dest) {
            res = dist;
        }
        
        for(int i = 0; i < map[x].size(); i++) {            
            int nx = map[x][i].first;
            int ndist = map[x][i].second;
            
            if(!visited[nx]) {
                visited[nx] = 1;
                q.push({nx, ndist + dist});
            }
        }
    }
}

int main() {
    cin >> n >> m;
    
    for(int i = 0; i < n-1; i++) {
        int a, b, d;
        cin >> a >> b >> d;
        map[a].push_back({b, d});
        map[b].push_back({a, d});
    }
    
    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        
        BFS(a, b);
        cout << res << endl;
        memset(visited, 0, sizeof(visited));
    }
}
/*
 4 2
 2 1 2
 4 3 2
 1 4 3
 1 2
 3 2
 */
