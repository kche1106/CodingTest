//
//  5427.cpp
//  DataStructure
//
//  Created by 김채은 on 2024/02/05.
//

#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int w, h;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
char map[1001][1001];
int visited[1001][1001];
int dist[1001][1001];
queue<pair<int, int>> sang;
queue<pair<int, int>> fire;
int res;

void movefire() {
    int size = fire.size();
    while(size--) {
        int x = fire.front().first;
        int y = fire.front().second;
        fire.pop();
        
        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < 0 || ny < 0 || nx >= h || ny >= w) continue;
            
            if(map[nx][ny] == '.' || map[nx][ny] == '@') {
                map[nx][ny] = '*';
                fire.push({nx, ny});
            }
        }
    }
}

void movesang() {
    int size = sang.size();
    while(size--) {
        int x = sang.front().first;
        int y = sang.front().second;
        sang.pop();
        
        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(nx < 0 || ny < 0 || nx >= h || ny >= w)
                res = dist[x][y] + 1;
            
            if(map[nx][ny] == '*' || map[nx][ny] == '#') continue;
            
            if(!visited[nx][ny]) {
                visited[nx][ny] = 1;
                sang.push({nx, ny});
                dist[nx][ny] = dist[x][y] + 1;
            }
        }
    }
}

void reset() {
    memset(map, 0, sizeof(map));
    while(!sang.empty()) sang.pop();
    while(!fire.empty()) fire.pop();
    memset(visited, 0, sizeof(visited));
    memset(dist, 0, sizeof(dist));
    res = 0;
}

int main() {
    int t;
    cin >> t;
    
    while(t--) {
        cin >> w >> h;
        
        for(int i = 0; i < h; i++) {
            for(int j = 0; j < w; j++) {
                cin >> map[i][j];
                if(map[i][j] == '@') sang.push({i, j});
                else if(map[i][j] == '*') fire.push({i, j});
            }
        }
        
        while(!sang.empty()) {
            movefire();
            movesang();
            
            if(res > 0) break;
        }
        
        if(res > 0) cout << res << endl;
        else cout << "IMPOSSIBLE" << endl;
        
        reset();
    }
}
