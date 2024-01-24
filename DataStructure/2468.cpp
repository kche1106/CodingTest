//
//  2468.cpp
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
    int n;
    cin >> n;
    
    int map[100][100];
    int max = 0;  //최대 높이
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> map[i][j];
            if(max < map[i][j]) max = map[i][j];
        }
    }
    
    int res = 0;
    for(int k = 0; k <= 100; k++) {
        
        int tmp[100][100] = {0, };
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(map[i][j] <= k) tmp[i][j] = 1;  //위험 지역
            }
        }
        
        queue<pair<int, int>> q;
        int cnt = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(tmp[i][j] == 0) {
                    cnt++;
                    q.push({i, j});
                    tmp[i][j] = 1;
                    
                    while(!q.empty()) {
                        int x = q.front().first;
                        int y = q.front().second;
                        q.pop();
                        
                        for(int i = 0; i < 4; i++) {
                            int nx = x + dx[i];
                            int ny = y + dy[i];
                            
                            if(nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
                            
                            if(tmp[nx][ny] == 0) {
                                q.push({nx, ny});
                                tmp[nx][ny] = 1;
                            }
                        }
                    }
                }
            }
        }
        if(res < cnt) res = cnt;
    }
    
    cout << res << endl;
}
