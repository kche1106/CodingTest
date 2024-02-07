//
//  2573.cpp
//  DataStructure
//
//  Created by 김채은 on 2024/02/07.
//

#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int n, m;
int map[300][300];
int visited[300][300];
int temp[300][300];
queue<pair<int, int>> q;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, 1, -1};

void check(int x, int y) {
    q.push({x, y});
    visited[x][y] = 1;
    
    while (!q.empty()) {
        int qx = q.front().first;
        int qy = q.front().second;
        q.pop();
        
        for(int i = 0; i < 4; i++) {
            int nx = qx + dx[i];
            int ny = qy + dy[i];
            
            if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            if(visited[nx][ny] == 0 && map[nx][ny] > 0) {
                visited[nx][ny] = 1;
                q.push({nx, ny});
            }
        }
    }
}

void melt() {
    memset(temp, 0, sizeof(temp));
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            int cnt = 0;
            for(int k = 0; k < 4; k++) {
                int nx = i + dx[k];
                int ny = j + dy[k];
                if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
                if(map[nx][ny] == 0) cnt++;
            }
            if(map[i][j] - cnt > 0) temp[i][j] = map[i][j] - cnt;
        }
    }
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            map[i][j] = temp[i][j];
        }
    }
}

int main() {
    cin >> n >> m;
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> map[i][j];
        }
    }
    
    int year = 0;
    while(true) {
        int cnt = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(visited[i][j] == 0 && map[i][j] > 0) {
                    check(i, j);
                    cnt++;
                }
            }
        }
        
        if(cnt == 0) {
            cout << "0";
            break;
        }  //cnt가 1이면 아직 분리되기 전이므로 계속 반복
        else if(cnt >= 2) {
            cout << year;
            break;
        }
        
        year += 1;
        melt();
        
        memset(visited, 0, sizeof(visited));
    }
}
