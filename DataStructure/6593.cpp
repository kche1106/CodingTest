//
//  6593.cpp
//  DataStructure
//
//  Created by 김채은 on 2024/01/24.
//

#include <iostream>
#include <string>
#include <queue>
#include <tuple>
using namespace std;

int dl[] = {-1 ,1, 0, 0, 0, 0};
int dr[] = {0, 0, -1 ,1, 0, 0};
int dc[] = {0, 0, 0, 0, -1 ,1};

int main() {
    while (true) {
        int l, r, c;
        cin >> l >> r >> c;
        if(l == 0 && r == 0 && c == 0) break;
        
        char map[30][30][30];
        int start_l, start_r, start_c;
        for(int i = 0; i < l; i++) {  //층
            for(int j = 0; j < r; j++) {  //행
                string s;
                cin >> s;
                for(int k = 0; k < c; k++) {  //열
                    map[i][j][k] = s[k];
                    if(map[i][j][k] == 'S') {
                        start_l = i; start_r = j; start_c = k;
                    }
                }
            }
        }
        
        queue<tuple<int, int, int>> q;
        q.push({start_l, start_r, start_c});
        map[start_l][start_r][start_c] = '#';
        
        int time = 0;
        int dist[30][30][30] = {0, };
        
        while (!q.empty()) {
            int x = get<0>(q.front());
            int y = get<1>(q.front());
            int z = get<2>(q.front());
            q.pop();
            
            for(int i = 0; i < 6; i++) {
                int nx = x + dl[i];
                int ny = y + dr[i];
                int nz = z + dc[i];
                
                if(nx < 0 || ny < 0 || nz < 0 || nx >= l || ny >= r || nz >= c) continue;
                if(map[nx][ny][nz] == '.') {
                    q.push({nx, ny, nz});
                    map[nx][ny][nz] = '#';
                    dist[nx][ny][nz] = dist[x][y][z] + 1;
                }
                if(map[nx][ny][nz] == 'E') {
                    dist[nx][ny][nz] = dist[x][y][z] + 1;
                    time = dist[nx][ny][nz];
                    break;
                }
            }
        }
        
        if(time) cout << "Escaped in " << time << " minute(s)." << endl;
        else cout << "Trapped!" << endl;
    }
}
