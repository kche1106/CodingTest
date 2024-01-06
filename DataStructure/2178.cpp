//
//  2178.cpp
//  DataStructure
//
//  Created by 김채은 on 2024/01/04.
//

#include <iostream>
using namespace std;

int arr[101][101], visited[101][101];
int n, m;
int res = 987654321;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

void DFS(int x, int y, int cnt) {
    
    cout << "x = " << x << " y = " << y << " cnt = " << cnt << endl;
    
    if(x == n && y == m) {
        cout << "end\n";
        if(res > cnt) res = cnt;
        visited[x][y] = 0;
        return;
    }
    
    if(x <= 0 || y <= 0 || x > n || y > m) return;
    
    cnt++;
    
    for(int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        
        if(arr[nx][ny] != 0 && visited[nx][ny] != 1) {
//            cout << "-- nx = " << nx << " ny = " << ny << endl;
            visited[nx][ny] = 1;
            DFS(nx, ny, cnt);
            visited[nx][ny] = 0;
        }
    }
    
}

int main() {
    cin >> n >> m;
    
    for(int i = 1; i <= n; i++) {
        int num;
        cin >> num;
        for(int j = m; j >= 1; j--) {
            arr[i][j] = num % 10;
            num /= 10;
        }
    }
    
    visited[1][1] = 1;
    DFS(1, 1, 1);
    
    cout << res << endl;
}
