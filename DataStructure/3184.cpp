//
//  3184.cpp
//  DataStructure
//
//  Created by 김채은 on 2023/09/18.
//

#include<iostream>
#include<queue>
using namespace std;
 
int R, C, wolf, sheep;
char arr[250][250];
bool Visit[250][250];
 
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };
 
void BFS(int a, int b)
{
    int w, s;
    w = s = 0;
    queue<pair<int, int>> Q;
    Q.push(make_pair(a, b));
    Visit[a][b] = true;
 
    while (Q.empty() == 0) {
        int x = Q.front().first;
        int y = Q.front().second;
        Q.pop();
        
        if (arr[x][y] == 'v') w++;
        if (arr[x][y] == 'o') s++;
 
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
 
            if (nx >= 0 && ny >= 0 && nx < R && ny < C) {
                if (arr[nx][ny] != '#' && Visit[nx][ny] == false) {
                    Visit[nx][ny] = true;
                    Q.push(make_pair(nx, ny));
                }
            }
        }
    }
 
    if (s > w) sheep = sheep + s;
    else wolf = wolf + w;
}
 
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> R >> C;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> arr[i][j];
        }
    }
    
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (Visit[i][j] == false) {
                BFS(i, j);
            }
        }
    }
 
    cout << sheep << " " << wolf << endl;
}
