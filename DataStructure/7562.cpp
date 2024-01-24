//
//  7562.cpp
//  DataStructure
//
//  Created by 김채은 on 2024/01/24.
//

#include <iostream>
#include <queue>
using namespace std;

int dx[] = {-1, -2, -2, -1, 1, 2, 2, 1};
int dy[] = {-2, -1, 1, 2, -2, -1, 1, 2};

int main() {
    int tc;
    cin >> tc;
    
    for(int t = 0; t < tc; t++) {
        int l;
        cin >> l;
        
        int night_x, night_y, move_x, move_y;
        cin >> night_x >> night_y >> move_x >> move_y;
        
        queue<pair<int, int>> q;
        q.push({night_x, night_y});
        
        int ch[300][300] = {0, };
        ch[night_x][night_y] = 1;
        
        while (!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            
            if(x == move_x && y == move_y) break;
            
            for(int i = 0; i < 8; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                
                if(nx < 0 || ny < 0 || nx >= l || ny >= l) continue;
                if(ch[nx][ny] == 0) {
                    ch[nx][ny] = ch[x][y] + 1;
                    q.push({nx, ny});
                }
            }
        }
        
        cout << ch[move_x][move_y] - 1 << endl;
        
    }
}
