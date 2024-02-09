//
//  4179.cpp
//  DataStructure
//
//  Created by 김채은 on 2024/02/09.
//

#include<iostream>
#include<string>
#include<queue>
#include<utility>
using namespace std;

char map[1001][1001];

int fdist[1001][1001]; //불의 전파 시간
int jdist[1001][1001]; // 탈출 속도

int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };

int main() {
    
    int n, m;
    cin >> n >> m;

    queue<pair<int, int>> fire; //불
    queue<pair<int, int>> jihoon; //탈출
    for (int i = 0; i < n; i++) {
        fill(fdist[i], fdist[i] + m, -1);
        fill(jdist[i], jdist[i] + m, -1);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> map[i][j];
            if (map[i][j] == 'F') {
                fire.push({ i,j });
                fdist[i][j] = 0;
            }
            if (map[i][j] == 'J') {
                jihoon.push({ i,j });
                jdist[i][j] = 0;
            }
        }
    }

    while (!fire.empty()) {
        int x = fire.front().first;
        int y = fire.front().second;
        fire.pop();

        for (int dir = 0; dir < 4; dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (fdist[nx][ny] >= 0 || map[nx][ny] == '#') continue;
            fdist[nx][ny] = fdist[x][y] + 1;
            fire.push({ nx,ny });

        }
    }


    while (!jihoon.empty()) {
        int x = jihoon.front().first;
        int y = jihoon.front().second;
        jihoon.pop();

        for (int dir = 0; dir < 4; dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
                cout << jdist[x][y] + 1;
                return 0;
            }
            if (jdist[nx][ny] >= 0 || map[nx][ny] == '#') continue;
            if (fdist[nx][ny] != -1 && fdist[nx][ny] <= jdist[x][y] + 1) continue;

            jdist[nx][ny] = jdist[x][y] + 1;
            jihoon.push({ nx,ny });
         }
    }
    cout << "IMPOSSIBLE";

}
