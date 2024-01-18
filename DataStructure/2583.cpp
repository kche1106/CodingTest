//
//  2583.cpp
//  DataStructure
//
//  Created by 김채은 on 2024/01/18.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int m, n, k;
int map[100][100];
queue<pair<int, int>> q;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
vector<int> ans;
int sum;

void BFS() {
    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            
            if(map[nx][ny] != 1) {
                sum += 1;
                map[nx][ny] = 1;
                q.push(make_pair(nx, ny));
            }
        }
    }
}

int main() {
    cin >> m >> n >> k;
    
    for(int i = 0; i < k; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        
        for(int i = x1; i < x2; i++) {
            for(int j = y1; j < y2; j++) {
                map[i][j] = 1;
            }
        }
    }
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(map[i][j] != 1) {
                map[i][j] = 1;
                q.push(make_pair(i, j));
                sum = 1;
                BFS();
                ans.push_back(sum);
            }
        }
    }
    
    sort(ans.begin(), ans.end());
    cout << ans.size() << endl;
    for(int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
}
