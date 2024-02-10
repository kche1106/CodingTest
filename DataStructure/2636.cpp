//
//  2636.cpp
//  DataStructure
//
//  Created by 김채은 on 2024/02/10.
//

#include <iostream>
#include <queue>
using namespace std;

int h, w;
int map[100][100];
int visited[100][100];
int tmp[100][100];

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int melt;
int before;

bool BFS() {
    queue<pair<int, int>> q;
    q.push({0,0});
    visited[0][0] = 1;
    
    melt++;  //녹는 시간
    int cheese = 0;
    
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(nx < 0 || ny < 0 || nx >= h || ny >= w || visited[nx][ny] == 1) continue;

            if(map[nx][ny] == 0) {
                visited[nx][ny] = 1;
                q.push({nx, ny});
            }
            else {  //인접한 곳이 치즈면
                map[nx][ny] = 0;  //공기로 바꿔줌
                cheese++;
                visited[nx][ny] = 1;
            }
        }
    }
    
    if(cheese == 0) { //치즈가 다 녹은 상태
        cout << melt - 1 << endl << before;
        return 1;
    }
    
    else {
        before = cheese;
        return 0;
    }
}

int main() {
    cin >> h >> w;
    
    for(int i = 0; i < h; i++) {
        for(int j = 0; j < w; j++) {
            cin >> map[i][j];
        }
    }
    
    while (true) {
        if(BFS()) break;  //다 녹았으면 실행 끝냄
        
        for(int i = 0; i < h; i++) {
            for(int j = 0; j < w; j++) {
                visited[i][j] = 0;
            }
        }
    }
}
