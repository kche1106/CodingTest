//
//  10026.cpp
//  DataStructure
//
//  Created by 김채은 on 2023/10/25.
//

#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int n;
char colors[101][101];
int dx[] = {-1,0,1,0};
int dy[] = {0,-1,0,1};
int isVisited[101][101];

void dfs1(int x, int y) {
    char color = colors[x][y];

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
        if(isVisited[nx][ny]) continue;

        if(color == colors[nx][ny]) {
            isVisited[nx][ny] = 1;
            dfs1(nx, ny);
        }
    }
}

void dfs2(int x, int y)
{
    char color = colors[x][y];

    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx < 0 || ny < 0 || nx >= n || ny >= n)
            continue;
        if (isVisited[nx][ny])
            continue;

        if (color == colors[nx][ny] || 
        (color == 'R' && colors[nx][ny] == 'G') ||
        (color == 'G' && colors[nx][ny] == 'R'))
        {
            isVisited[nx][ny] = 1;
            dfs2(nx, ny);
        }
    }
}

int main() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        string color;
        cin >> color;
        for(int j = 0; j < color.size(); j++) {
            colors[i][j] = color[j];
        }
    }
    
    int cnt1 = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!isVisited[i][j]) {
                isVisited[i][j] = 1;
                dfs1(i, j);
                cnt1++;
            }
        }
    }

    memset(isVisited, 0, sizeof(isVisited));

    int cnt2 = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (!isVisited[i][j])
            {
                isVisited[i][j] = 1;
                dfs2(i, j);
                cnt2++;
            }
        }
    }

    cout << cnt1 << " " << cnt2 << endl;
}
