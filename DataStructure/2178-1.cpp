//
//  2178-1.cpp
//  DataStructure
//
//  Created by 김채은 on 2024/01/06.
//

#include <iostream>
#include <queue>
using namespace std;

int arr[101][101], dist[101][101], visited[101][101];
int n, m;
int res = 10001;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

void DFS(int x, int y, int cnt) {

    if(x == n-1 && y == m-1) {
        if(res > cnt) res = cnt;
        return;
    }

    if(x < 0 || y < 0 || x >= n || y >= m) return;

    for(int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(arr[nx][ny] == 1 && visited[nx][ny] != 1) {
            visited[nx][ny] = 1;
            DFS(nx, ny, cnt+1);
            visited[nx][ny] = 0;
        }
    }

}


int main() {
    cin >> n >> m;
    
    for (int i = 0; i < n; i++) {
        string temp;
        cin >> temp;
        for (int j = 0; j < m; j++) {
            arr[i][j] = temp[j] - '0';
        }
    }
    
    DFS(0, 0, 1);
    
    cout << res << endl;
}

