//
//  1743.cpp
//  DataStructure
//
//  Created by 김채은 on 2024/01/07.
//

#include <iostream>
using namespace std;

int map[101][101];
int n, m, k;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
int cnt, res;

void DFS(int x, int y) {
        
    for(int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        
        if(nx > 0 && nx <= n && ny > 0 && ny <= m) {
            if(map[nx][ny] == 1) {
                cnt++;
                map[nx][ny] = 0;
                DFS(nx, ny);
            }
        }
    }
}

int main() {
    cin >> n >> m >> k;
    
    for(int i = 0; i < k; i++) {
        int r, c;
        cin >> r >> c;
        map[r][c] = 1;
    }
    
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(map[i][j] == 1) {
                cnt++;
                map[i][j] = 0;
                DFS(i, j);
            }
            if(res < cnt) res = cnt;
            cnt = 0;
        }
    }
    
    cout << res << endl;
}
