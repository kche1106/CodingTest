//
//  15683.cpp
//  DataStructure
//
//  Created by 김채은 on 2024/02/22.
//

#include <iostream>
#include <vector>
using namespace std;

int n, m;
int map[9][9];
vector<pair<int, int>> cctv;
int ans = 100000000;

int dx[4] = {0, 1, 0, -1};  //우, 하, 좌, 상
int dy[4] = {1, 0, -1, 0};

void check(int x, int y, int dir) {
    dir = dir % 4;
    while(true) {
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        x = nx;
        y = ny;
        
        if(nx < 0 || ny < 0 || nx >= n || ny >= m) return;
        if(map[nx][ny] == 6) return;  //벽 만났을 경우
        if(map[nx][ny] == 0) map[nx][ny] = -1;  //빈 공간일 경우 감시 가능
    }
}

void dfs(int idx) {
    
    if(idx == cctv.size()) {
        int cnt = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(map[i][j] == 0) cnt++;
            }
        }
        
        if(ans > cnt) ans = cnt;
        return;
    }
    
    int x = cctv[idx].first;
    int y = cctv[idx].second;
    int num = map[x][y];  //cctv 번호
    
    int temp[9][9];

    for(int dir = 0; dir < 4; dir++) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                temp[i][j] = map[i][j];
            }
        }
        
        if(num == 1) {
            check(x, y, dir);
        }
        else if(num == 2) {
            check(x, y, dir);
            check(x, y, dir+2);
        }
        else if(num == 3) {
            check(x, y, dir);
            check(x, y, dir+3);
        }
        else if(num == 4) {
            check(x, y, dir);
            check(x, y, dir+2);
            check(x, y, dir+3);
        }
        else if(num == 5) {
            check(x, y, dir);
            check(x, y, dir+1);
            check(x, y, dir+2);
            check(x, y, dir+3);
        }
        
        dfs(idx+1);  //다음 cctv
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                map[i][j] = temp[i][j];
            }
        }
    }
}

int main() {
    cin >> n >> m;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> map[i][j];
            if(map[i][j] > 0 && map[i][j] < 6) cctv.push_back({i, j});
        }
    }
    
    dfs(0);  //몇번 cctv인지
    cout << ans;
}
