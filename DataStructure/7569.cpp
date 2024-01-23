//
//  7569.cpp
//  DataStructure
//
//  Created by 김채은 on 2024/01/22.
//

#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

int m, n, h;
int box[100][100][100];
int dist[100][100][100];
int dh[] = {-1, 1, 0, 0, 0, 0};
int dn[] = {0, 0, -1, 1, 0, 0};
int dm[] = {0, 0, 0, 0, -1, 1};
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
            
            if(nh < 0 || nm < 0 || nn < 0 || nh >= h || nm >= m || nn >= n) continue;
            
            if(box[nh][nn][nm] == 0) {
                box[nh][nn][nm] = 1;
                dist[nh][nn][nm] = dist[qh][qn][qm] + 1;
                q.push({nh, nn, nm});
            }
            
        }
    }
}

int main() {
    cin >> m >> n >> h;  //가로, 세로, 높이
    
    for(int i = 0; i < h; i++) {
        for(int j = 0; j < n; j++) {
            for(int k = 0; k < m; k++) {
                cin >> box[i][j][k];  //높이, 세로, 가로
                if(box[i][j][k] == 0) dist[i][j][k] = -1;
            }
        }
    }
    
    for(int i = 0; i < h; i++) {
        for(int j = 0; j < n; j++) {
            for(int k = 0; k < m; k++) {
                if(box[i][j][k] == 1) q.push({i, j, k});  //안익은 토마토
            }
        }
    }
    
    BFS();
    
    for(int i = 0; i < h; i++) {
        for(int j = 0; j < n; j++) {
            for(int k = 0; k < m; k++) {
                if(dist[i][j][k] == -1) {  //안익은 토마토가 남아있음
                    cout << "-1" << endl;
                    return 0;
                }
            }
        }
    }
    
    int res = 0;
    for(int i = 0; i < h; i++) {
        for(int j = 0; j < n; j++) {
            for(int k = 0; k < m; k++) {
                if(res < dist[i][j][k]) res = dist[i][j][k];
            }
        }
    }
    
    cout << res << endl;
    
}
