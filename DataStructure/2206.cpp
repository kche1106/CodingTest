//
//  2206.cpp
//  DataStructure
//
//  Created by 김채은 on 2024/03/03.
//

#include <iostream>
#include <queue>
using namespace std;

int n, m;
int map[1001][1001];
int dist[1001][1001][2];
queue<pair<pair<int, int>, int>> q;
int res;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void bfs() {
    while(!q.empty()) {
        int x = q.front().first.first;
        int y = q.front().first.second;
        int cnt = q.front().second;
        q.pop();
        
        if(x == n-1 && y == m-1) {
            res = dist[x][y][cnt];
            break;
        }
        
        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            
            if(map[nx][ny] == 1 && dist[nx][ny][1] == 0) {  //다음칸 벽
                if(cnt == 0) {  //부술 수 있음
                    dist[nx][ny][1] = dist[x][y][0] + 1;
                    q.push({{nx, ny}, cnt+1});
                }
            }
            else if(map[nx][ny] == 0 && dist[nx][ny][cnt] == 0) {  //다음칸 벽 아님
                dist[nx][ny][cnt] = dist[x][y][cnt] + 1;
                q.push({{nx, ny}, cnt});
            }
        }
    }
}

int main() {
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for(int j = 0; j < m; j++) {
            map[i][j] = s[j] - '0';
        }
    }
    
    dist[0][0][0] = 1;
    q.push({{0, 0}, 0});
    bfs();
   
    if(!res) cout << -1;
    else cout << res;
}
