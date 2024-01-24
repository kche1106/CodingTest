//
//  1012.cpp
//  DataStructure
//
//  Created by 김채은 on 2024/01/24.
//

#include <iostream>
#include <queue>
using namespace std;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int main() {
    int tc;
    cin >> tc;
    
    for(int t = 0; t < tc; t++) {
        int m, n, k;  //가로, 세로, 배추 위치 개수
        cin >> m >> n >> k;
        
        int map[50][50];
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                map[i][j] = 0;
            }
        }
        
        queue<pair<int, int>> q;
        int ch[50][50] = {0, };
        for(int i = 0; i < k; i++) {
            int a, b;
            cin >> b >> a;
            map[a][b] = 1;
        }
        
        int cnt = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(map[i][j] == 1 && ch[i][j] == 0) {
                    q.push({i, j});
                    ch[i][j] = 1;
                    cnt++;
                    
                    while(!q.empty()) {
                        int x = q.front().first;
                        int y = q.front().second;
                        q.pop();
                        
                        for(int i = 0; i < 4; i++) {
                            int nx = x + dx[i];
                            int ny = y + dy[i];
                            
                            if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
                            if(map[nx][ny] == 1 && ch[nx][ny] == 0) {
                                ch[nx][ny] = 1;
                                q.push({nx, ny});
                            }
                        }
                    }
                }
                
            }
        }
        cout << cnt << endl;
    }
}
