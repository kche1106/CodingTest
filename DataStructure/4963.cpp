//
//  4963.cpp
//  DataStructure
//
//  Created by 김채은 on 2023/10/22.
//

#include <iostream>
using namespace std;

int w, h;
int map[51][51];
int isVisit[51][51];
int dx[8] = { -1, 1, -1, 1, 0, 0, -1, 1};
int dy[8] = { -1, 1, 1, -1, 1, -1, 0, 0 };

void DFS(int x, int y) {
    isVisit[x][y] = 1;
    
    for(int i = 0; i < 8; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        
        if(nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
        
        if(!isVisit[nx][ny] && map[nx][ny] == 1) {
            DFS(nx, ny);
        }
    }
}

int main() {
    
    while (true) {
        int cnt = 0;
        
        cin >> w >> h;
        
        if(w == 0 && h == 0) break;
        
        for(int i = 0; i < h; i++) {
            for(int j = 0; j < w; j++) {
                isVisit[i][j] = 0;
                cin >> map[i][j];
            }
        }
        
        for(int i = 0; i < h; i++) {
            for(int j = 0; j < w; j++) {
                if(!isVisit[i][j] && map[i][j] == 1) {
                    isVisit[i][j] = 1;
                    cnt++;
                    DFS(i, j);
                }
            }
        }
        cout << cnt << endl;
    }
}
