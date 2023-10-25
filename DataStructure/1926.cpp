//
//  1926.cpp
//  DataStructure
//
//  Created by 김채은 on 2023/10/25.
//

#include <iostream>
#include <vector>
using namespace std;

int n, m;
int paint[501][501];
int isVisit[501][501];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
vector<int> width;
int cnt, sum;

void DFS(int x, int y) {
    isVisit[x][y] = 1;
    
    for(int i = 0; i < 4; i++) {
        int rx = x + dx[i];
        int ry = y + dy[i];
        
        if(rx < 0 || rx >= n || ry < 0 || ry >= m) continue;
        if(!isVisit[rx][ry] && paint[rx][ry] == 1) {
            cnt++;
            DFS(rx, ry);
        }
     }
    
}

int main() {
    cin >> n >> m;
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> paint[i][j];
        }
    }
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(!isVisit[i][j] && paint[i][j] == 1) {
                sum ++;
                cnt = 0;
                cnt ++;
                DFS(i, j);
                width.push_back(cnt);
            }
        }
    }
    
    int max = 0;
    for(int i = 0; i < width.size(); i++) {
        if(width[i] > max) max = width[i];
    }
        
    cout << sum << endl;
    cout << max << endl;
}
