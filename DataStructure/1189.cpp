#include <iostream>
#include <string.h>
using namespace std;

int r, c, k;
char map[6][6];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int visited[6][6];
int res;

void dfs(int x, int y, int dist) {

    // cout << "x = " << x << " y = " << y << endl;

    if (x == 0 && y == c - 1) {
        if(dist == k) res++;
        return;
    }

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx < 0 || ny < 0 || nx >= r || ny >= c)
            continue;

        if (!visited[nx][ny] && map[nx][ny] != 'T') {
            // cout << "dist = " << dist << endl;
            visited[nx][ny] = 1;
            dfs(nx, ny, dist+1);
            visited[nx][ny] = 0;
        }
    }
}

int main() {
    cin >> r >> c >> k;

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> map[i][j];
        }
    }

    int x = r - 1;
    int y = 0;
    visited[x][y] = 1;

    dfs(x, y, 1);

    cout << res;
}