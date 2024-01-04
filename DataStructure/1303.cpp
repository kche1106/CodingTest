//
//  1303.cpp
//  DataStructure
//
//  Created by 김채은 on 2024/01/04.
//

#include <iostream>
using namespace std;

char map[101][101];
bool visited[101][101];
int n, m;
int w, b, w_pow, b_pow;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

void DFS(int x, int y) {
    
    if(x < 0 || y < 0 || x >= m || y >= n) return;
    if(visited[x][y] == 1) return;
    
    if(map[x][y] == 'W') w++;
    else if(map[x][y] == 'B') b++;
    
    for(int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        
        if(map[x][y] == map[nx][ny]) {
            visited[x][y] = 1;
            DFS(nx, ny);
        }
    }
}

int main() {
    cin >> n >> m;
    
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            char c;
            cin >> c;
            map[i][j] = c;
        }
    }
    
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(visited[i][j] != 1) DFS(i, j);
            w_pow += w * w;
            b_pow += b * b;
            w = 0;
            b = 0;
        }
    }
    
    cout << w_pow << " " << b_pow << endl;
}
