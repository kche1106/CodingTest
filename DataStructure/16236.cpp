//
//  16236.cpp
//  DataStructure
//
//  Created by 김채은 on 2024/04/03.
//

#include <iostream>
#include <queue>
using namespace std;

int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};
int map[21][21];
queue<pair<int, int>> q;
int shark_size = 2;
int times;
bool stop = false;
bool eat = false;

bool bfs() {

    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        map[x][y] = 0;
        times++;
        
        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(map[nx][ny] >= 1 && map[nx][ny] <= 6) {
                if(map[nx][ny] < shark_size) {
                    q.push({nx, ny});
                    shark_size += map[nx][ny];
                }
                else if(map[nx][ny] == shark_size) {
                    q.push({nx, ny});
                }
                break;
            }
        }
    }
    
    return false;
}

int main() {
    int n;
    cin >> n;

    int startx, starty;
    vector<pair<int, int>> fish;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> map[i][j];
            if(map[i][j] == 9) {
                startx = i;
                starty = j;
                map[i][j] = 0;
            }
        }
    }
    
    q.push({startx, starty});
    
    while(!stop) {
        bool visited[21][21];
        memset(visited, 0, sizeof(visited));
        
        if(eat) {
            eat = false;
            
        }
        else {
            stop = true;
        }
        
    }
    
    cout << times;
    
}
