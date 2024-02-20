//
//  3190.cpp
//  DataStructure
//
//  Created by 김채은 on 2024/02/19.
//

#include <iostream>
#include <queue>
using namespace std;

#define SNAKE 1
#define APPLE 2

int map[101][101];  //뱀 1, 사과 2
int dx[] = {0, 1, 0, -1};  //우, 하, 좌, 상
int dy[] = {1, 0, -1, 0};

int main() {
    int n, k;
    cin >> n >> k;  //보드 크기, 사과 개수
    
    for(int i = 0; i < k; i++) {
        int x, y;
        cin >> x >> y;
        map[x][y] = APPLE;  //사과
    }
    
    int l;  //방향 변환 횟수
    cin >> l;
    
    queue<pair<int, int>> rot;
    for(int i = 0; i < l; i++) {
        int X; char C;
        cin >> X >> C;
        
        rot.push({X, C});
    }
    
    int sec = 0;
    int x = 1;
    int y = 1;
    int dir = 0;
    queue<pair<int, int>> snake;
    snake.push({x, y});
        
    while(true) {
        sec++;
        
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        
        if(nx <= 0 || ny <= 0 || nx > n || ny > n || map[nx][ny] == SNAKE) break;
        
        if(map[nx][ny] == APPLE) {
            map[nx][ny] = SNAKE;
            snake.push({nx, ny});
        }
        else {
            map[nx][ny] = SNAKE;
            snake.push({nx, ny});
            map[snake.front().first][snake.front().second] = 0;  //꼬리 부분 지우기
            snake.pop();
        }
        
        x = nx;
        y = ny;
        
        if(rot.front().first == sec) {
            if(rot.front().second == 'D') {  //우측 회전
                dir = (dir + 1) % 4;
            }
            else {  //좌측 회전
                dir = (dir + 3) % 4;
            }
            rot.pop();
        }
    }
    
    cout << sec;
}

