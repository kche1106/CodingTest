//
//  1707.cpp
//  DataStructure
//
//  Created by 김채은 on 2024/02/15.
//

#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;

vector<int> graph[20001];
int visited[20001];

void BFS(int i) {
    queue<int> q;
    q.push(i);
    visited[i] = 1;
    
    while(!q.empty()) {
        int x = q.front();
        q.pop();
        
        for(int i = 0; i < graph[x].size(); i++) {
            int nx = graph[x][i];
                
            if(!visited[nx]) {
                q.push(nx);
                if(visited[x] == 1) visited[nx] = 2;
                else if(visited[x] == 2) visited[nx] = 1;
            }
        }
    }
}

int main() {
    int k;
    cin >> k;
    
    while(k--) {
        int V, e;
        cin >> V >> e;
        
        for(int i = 0; i < e; i++) {
            int u, v;
            cin >> u >> v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        
        for(int i = 1; i <= V; i++) {
            if(!visited[i]) {
                BFS(i);
            }
        }
        
        string res = "YES";
        for(int i = 1; i <= V; i++) {
            for(int j = 0; j < graph[i].size(); j++) {
                int next = graph[i][j];
                if(visited[i] == visited[next]) res = "NO";
            }
        }
        cout << res << endl;
        
        for(int i = 0; i <= V; i++) {
            graph[i].clear();
        }
        memset(visited, 0, sizeof(visited));
    }
}
