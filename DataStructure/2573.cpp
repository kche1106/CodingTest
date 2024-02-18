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
int map[301][301];
int visited[301][301];

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

void melt() {
    int temp[301][301];
    memset(temp, 0, sizeof(temp));
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(map[i][j] == 0) continue;
            
            int cnt = 0;
            for(int d = 0; d < 4; d++) {
                int nx = i + dx[d];
                int ny = j + dy[d];
                
                if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
                
                if(map[nx][ny] == 0) cnt++;
            }
            
            temp[i][j] = map[i][j] - cnt;
            if(temp[i][j] < 0) temp[i][j] = 0;
        }
    }
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            map[i][j] = temp[i][j];
        }
    }
}

void check(int x, int y) {
    visited[x][y] = 1;
    
    for(int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        
        if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
        
        if(!visited[nx][ny] && map[nx][ny] > 0) {
            visited[nx][ny] = 1;
            check(nx, ny);
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
    
    int res = 0;
    while (true) {
        res += 1;
        melt();
        
        int cnt = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(map[i][j] > 0 && !visited[i][j]) {
                    cnt++;
                    visited[i][j] = 1;
                    check(i, j);
                }
            }
        }
        memset(visited, 0, sizeof(visited));
                
        if(cnt >= 2) {
            cout << res;
            break;
        }
        else if(cnt == 0) {
            cout << "0";
            break;
        }
    }
}
