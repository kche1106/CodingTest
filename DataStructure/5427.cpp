//
//  5427.cpp
//  DataStructure
//
//  Created by 김채은 on 2024/02/05.
//

#include <iostream>
#include <queue>
using namespace std;

int w, h;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
char map[1001][1001];
queue<pair<int, int>> sang;
queue<pair<int, int>> fire;

void moveFire() {
    int cnt = fire.size();
    for(int j = 0; j < cnt; j++) {
        int fx = fire.front().first;
        int fy = fire.front().second;
        fire.pop();
        
        for(int i = 0; i < 4; i++) {
            int fnx = fx + dx[i];
            int fny = fy + dy[i];
            
            //불 퍼져나감
            if(fnx >= 0 && fny >= 0 && fnx < h && fny < w) {
                if(map[fnx][fny] == '.') {  //상근이가 지나온 곳은 갈 필요 없음
                    map[fnx][fny] = '*';
                    fire.push({fnx, fny});
                }
            }
        }
    }
}

int moveSang() {
    int res = 0;
    while(!sang.empty()) {
        res++;
        moveFire();
        
        int cnt = sang.size();
        for(int j = 0; j < cnt; j++) {
            int sx = sang.front().first;
            int sy = sang.front().second;
            sang.pop();
            
            for(int i = 0; i < 4; i++) {
                int snx = sx + dx[i];
                int sny = sy + dy[i];
                
                //상근이 이동
                if(snx < 0 || sny < 0 || snx >= h || sny >= w) {
                    return res;
                }

                if(map[snx][sny] == '.') {
                    sang.push({snx, sny});
                    map[snx][sny] = '@';
                }
            }
        }
    }
    return -1;
}

void reset() {
    while(!sang.empty()) sang.pop();
    while(!fire.empty()) fire.pop();
}

int main() {
    int tc;
    cin >> tc;
    
    while(tc--) {
        cin >> w >> h;
        
        for(int i = 0; i < h; i++) {
            for(int j = 0; j < w; j++) {
                cin >> map[i][j];
                if(map[i][j] == '@') sang.push({i, j});
                if(map[i][j] == '*') fire.push({i, j});
            }
        }
        
        int ans = moveSang();
        reset();
        
        if(ans == - 1) cout << "IMPOSSIBLE" << '\n';
        else cout << ans << '\n';
    
    }
}
