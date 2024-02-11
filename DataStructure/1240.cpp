//
//  1240.cpp
//  DataStructure
//
//  Created by 김채은 on 2024/02/11.
//

#include <iostream>
#include <cstring>
using namespace std;

int n, m;
int map[1001][1001];
int visited[1001];
int cost = 1000000000;

void DFS(int x, int y, int res) {    
    if(x == y) {
        if(cost > res) cost = res;
        return;
    }
    
    for(int i = 1; i <= n; i++) {
        if(map[x][i] > 0 && visited[i] == 0) {
            visited[i] = 1;
            DFS(i, y, res+map[x][i]);
            visited[i] = 0;
        }
    }
}

int main() {
    cin >> n >> m;
    
    for(int i = 0; i < n-1; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        map[a][b] = c;
        map[b][a] = c;
    }
    
    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        
        visited[a] = 1;
        DFS(a, b, 0);
        
        cout << cost << endl;
        
        cost = 1000000000;
        memset(visited, 0, sizeof(visited));
    }
}
