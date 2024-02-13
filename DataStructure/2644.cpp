//
//  2644.cpp
//  DataStructure
//
//  Created by 김채은 on 2024/02/03.
//

#include <iostream>
#include <queue>
using namespace std;

int visited[101];
int dist[101];

int main() {
    int n;
    cin >> n;
    
    int r1, r2;
    cin >> r1 >> r2;
    
    int m;
    cin >> m;
    
    vector<int> v[101];
    for(int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    
    queue<int> q;
    q.push(r1);
    visited[r1] = 1;
    
    int res = -1;
    while(!q.empty()) {
        int qx = q.front();
        q.pop();
        
        if(qx == r2) {
            res = dist[qx];
            break;
        }
        
        for(int i = 0; i < v[qx].size(); i++) {
            int nx = v[qx][i];
            
            if(visited[nx] == 0) {
                visited[nx] = 1;
                q.push(nx);
                dist[nx] = dist[qx] + 1;
            }
        }
    }
    
    cout << res;
}

