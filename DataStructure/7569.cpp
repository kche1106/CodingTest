//
//  7569.cpp
//  DataStructure
//
//  Created by 김채은 on 2024/01/22.
//

#include <iostream>
#include <queue>
#include <tuple>
#include <algorithm>
using namespace std;

int m, n, h;
int box[100][100][100];
int dist[100][100][100];
int dm[] = {-1, 1, 0, 0, 0, 0};
int dn[] = {0, 0, -1, 1, 0, 0};
int dh[] = {0, 0, 0, 0, -1, 1};
queue<tuple<int, int, int>> q;

void BFS() {
    while(!q.empty()) {
        int qh = get<0>(q.front());
        int qn = get<1>(q.front());
        int qm = get<2>(q.front());
        q.pop();
        
        for(int i = 0; i < 6; i++) {
            int nh = qh + dh[i];
            int nn = qn + dn[i];
            int nm = qm + dm[i];
                        
            if(nh < 0 || nh >= h || nn < 0 || nn >= n || nm < 0 || nm >= m) continue;
            if(dist[nh][nn][nm] == -1) {  //안익은 토마토
                dist[nh][nn][nm] = dist[qh][qn][qm] + 1;
                q.push(make_tuple(nh, nn, nm));
            }
        }
    }
}

int main() {
    cin >> m >> n >> h;
    
    for(int i = 0; i < h; i++) {
        for(int j = 0; j < n; j++) {
            for(int k = 0; k < m; k++) {
                cin >> box[i][j][k];
                if(box[i][j][k] == 1) q.push(make_tuple(i, j, k));  //익은 토마토 큐에 넣어줌
                else if(box[i][j][k] == 0) dist[i][j][k] = -1;  //안익은 토마토
            }
        }
    }
    
    BFS();
    
    int day = 0;
    for(int i = 0; i < h; i++) {
        for(int j = 0; j < n; j++) {
            for(int k = 0; k < m; k++) {
                //익지 않은 토마토가 있으면
                if(dist[i][j][k] == -1) {
                    cout << "-1" << endl;
                    return 0;
                }
                day = max(day, dist[i][j][k]);  //처음부터 토마토가 다 익어있으면 dist 배열에는 0밖에 없음
            }
        }
    }
    
    cout << day << endl;
}
