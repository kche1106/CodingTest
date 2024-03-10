//
//  6248.cpp
//  softeer
//
//  Created by 김채은 on 2024/03/10.
//

#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

vector<int> map[100001];
vector<int> rmap[100001];
int visited1[100001];
int visited2[100001];
int visited3[100001];
int visited4[100001];

void dfs(int f, int visited[], vector<int> v[]) {
    if(visited[f]) return;
    
    visited[f] = 1;
    for(auto a : v[f]) {
        dfs(a, visited, v);
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    
    for(int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        map[x].push_back(y);
        rmap[y].push_back(x);
    }
    
    int s, t;
    cin >> s >> t;
    
    visited1[t] = 1;
    visited2[s] = 1;
    dfs(s, visited1, map);
    dfs(t, visited2, map);
    dfs(s, visited3, rmap);
    dfs(t, visited4, rmap);
    
    int res = 0;
    for(int i = 1; i <= n; i++) {
        if(visited1[i] && visited2[i] && visited3[i] && visited4[i]) {
            res++;
        }
    }
    cout << res-2;
}
