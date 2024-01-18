//
//  14503.cpp
//  DataStructure
//
//  Created by 김채은 on 2024/01/17.
//

#include <iostream>
using namespace std;

int n, m;
int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};
int map[51][51];
int visited[51][51];  //후진할 경우 벽이 아닌 방문했던 곳으로 후진할 수 있으므로 visited 배열이 필요(후진을 못하는 경우는 벽일 경우에만)

void DFS(int r, int c, int d, int sum){
    for(int i = 0; i < 4; i++) {
        int nd = (d + 3 - i) % 4;   //이건 더 고민해봐야..
        int nr = r + dr[nd];
        int nc = c + dc[nd];
        
        if(nr < 0 || nr >= n || nc < 0 || nc >= m || map[nr][nc] == 1) continue;
        
        if(map[nr][nc] == 0 && visited[nr][nc] == 0) {
            visited[nr][nc] = 1;
            DFS(nr, nc, nd, sum+1);
        }
    }
    
    int back = d < 2 ? d + 2 : d - 2;
    int br = r + dr[back];
    int bc = c + dc[back];
    
    if(br >= 0 && br < n && bc >= 0 && bc < m) {
        if(map[br][bc] != 1) {  //벽이 아닐 경우에만 후진 가능
            DFS(br, bc, d, sum);
        }
        else {
            cout << sum << endl;
            exit(0);
        }
    }
}

int main() {
    cin >> n >> m;
    
    int r, c, d;
    cin >> r >> c >> d;
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> map[i][j];
        }
    }
    
    visited[r][c] = 1;
    DFS(r, c, d, 1);
}
