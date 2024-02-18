//
//  14502.cpp
//  DataStructure
//
//  Created by 김채은 on 2024/02/18.
//

#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int n, m;
int map[9][9];
int temp[9][9];  //벽 세운 지도
int res;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

void copy(int a[9][9], int b[9][9]) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            a[i][j] = b[i][j];
        }
    }
}

void virus() {
    queue<pair<int, int>> q;
    int spread[9][9];
    copy(spread, temp);
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(spread[i][j] == 2) q.push({i, j});
        }
    }
    
    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            if(spread[nx][ny] == 0) {
                q.push({nx, ny});
                spread[nx][ny] = 2;
            }
        }
    }
    
    int cnt = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(spread[i][j] == 0) cnt++;
        }
    }
    
    if(cnt > res) res = cnt;
}

void wall(int cnt) {
    if(cnt == 3) {
        virus();
        return;
    }
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(temp[i][j] == 0) {
//                copy(temp, map);
                temp[i][j] = 1;  //벽 세움
                wall(cnt + 1);
                temp[i][j] = 0;
            }
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
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(map[i][j] == 0) {
                copy(temp, map);
                temp[i][j] = 1;
                wall(1);  //벽 개수
                temp[i][j] = 0;
            }
        }
    }
    
    cout << res;
}
