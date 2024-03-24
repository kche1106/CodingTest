//
//  17484.cpp
//  DataStructure
//
//  Created by 김채은 on 2024/03/20.
//

#include <iostream>
using namespace std;

int n, m;
int map[7][7];
int dx[3] = {-1, 0, 1};
int res = 1e9+10;

void dfs(int l, int x, int dir, int sum) {
    if(l == n) {
        if(res > sum) res = sum;
    }
    
    else {
        for(int i = 0; i < 3; i++) {
            if(i == dir) continue;
            
            int nx = x + dx[i];
            if(nx < 0 || nx >= m) continue;
            
            dfs(l+1, nx, i, sum + map[l+1][nx]);
            
        }
    }
}

int main() {
    cin >> n >> m;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> map[i][j];
        }
    }
    
    for(int i = 0; i < m; i++) {
        dfs(0, i, -1, map[0][i]);
    }
    
    cout << res;
}
