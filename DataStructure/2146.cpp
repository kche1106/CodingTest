//
//  2146.cpp
//  DataStructure
//
//  Created by 김채은 on 2024/03/01.
//

#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int n;
int map[101][101];
int con[101][101];
int visited[101][101];
queue<pair<int, int>> q;  //그룹 설정할 때 쓰는 큐
int dist[101][101];
int res = 10000000;

int dx[4] = {-1 ,1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void chgroup(int group) {
    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
            if(!visited[nx][ny] && map[nx][ny]) {
                visited[nx][ny] = 1;
                con[nx][ny] = group;
                q.push({nx, ny});
            }
        }
    }
}

void BFS(int group) {
    queue<pair<int, int>> is;
        
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(con[i][j] == group) {
                visited[i][j] = 1;
                is.push({i, j});
            }
        }
    }
    
    while(!is.empty()) {
        int x = is.front().first;
        int y = is.front().second;
        is.pop();
        
        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
            if(con[nx][ny] != 0 && con[nx][ny] != group) {
                res = min(res, dist[x][y]);
                return;
            }
            if(!visited[nx][ny]) {
                visited[nx][ny] = 1;
                dist[nx][ny] = dist[x][y] + 1;
                is.push({nx, ny});
            }
        }
    }
}

int main() {
    cin >> n;
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> map[i][j];
        }
    }
    
    int group = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(!visited[i][j] && map[i][j]) {
                group++;
                con[i][j] = group;
                q.push({i, j});
                chgroup(group);
            }
        }
    }
    
    for(int i = 1; i <= group; i++) {
        memset(visited, 0, sizeof(visited));
        memset(dist, 0, sizeof(dist));
        BFS(i);
    }
    
    cout << res << '\n';
}

/*
 4
 1 0 0 1
 0 0 0 0
 0 1 1 0
 0 0 0 0
 */
