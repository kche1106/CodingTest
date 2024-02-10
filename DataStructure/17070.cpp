//
//  17070.cpp
//  DataStructure
//
//  Created by 김채은 on 2024/02/10.
//

#include <iostream>
#include <queue>
using namespace std;

int n;
int map[17][17];
int dx[] = {0, 1, 1};
int dy[] = {1, 1, 0};
int res;

void DFS(int x, int y, int dir) {
    if(x == n && y == n) {
        res++;
        return;
    }
    
    for(int i = 0; i < 3; i++) {
        if((dir == 0 && i == 2) || (dir == 2 && i == 0)) continue;
        
        int nx = x + dx[i];
        int ny = y + dy[i];
        
        if(nx <= 0 || ny <= 0 || nx > n || ny > n ) continue;
        if(map[nx][ny] == 1) continue;
        if(i == 1) {
            if(map[nx-1][ny] == 1 || map[nx][ny-1] == 1) continue;
        }
        
        DFS(nx, ny, i);
    }
}

int main() {
    cin >> n;
    
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> map[i][j];
        }
    }
    
    DFS(1, 2, 0);
    
    cout << res;
}
