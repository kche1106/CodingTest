//
//  13913.cpp
//  DataStructure
//
//  Created by 김채은 on 2024/01/23.
//

#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int n, k;
int t, res;
int visited[1000000];
int dist[1000000];
queue<int> q;
int p[1000000];
vector<int> path;

void BFS() {
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        
        if(x == k) {
            res = dist[x];
            return;
        }
        
        for(int i = 0; i < 3; i++) {
            int nx = 0;
            if(i == 0) nx = x + 1;
            else if(i == 1) nx = x - 1;
            else if(i == 2) nx = 2 * x;
            
            if(nx >= 0 && nx <= 100000 && visited[nx] != 1) {
                dist[nx] = dist[x] + 1;
                visited[nx] = 1;
                p[nx] = x;
                q.push(nx);
            }
        }
        
    }
}

int main() {
    cin >> n >> k;
    
    q.push(n);
    visited[n] = 1;
    BFS();
    
    cout << res << endl;
    
    path.push_back(k);
    for(int i = 0; i < res; i++) {
        path.push_back(p[k]);
        k = p[k];
    }
    
    for(int i = path.size() - 1; i >= 0; i--) {
        cout << path[i] << " ";
    }
}
