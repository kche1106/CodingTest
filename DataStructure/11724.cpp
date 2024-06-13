//
//  11724.cpp
//  DataStructure
//
//  Created by 김채은 on 2023/10/21.
//

#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<int> arr[1001];
int visited[1001];

void dfs(int l) { 
    for (int i = 0; i < arr[l].size(); i++) {
        int x = arr[l][i];
        if(visited[x] == 0) {
            visited[x] = 1;
            dfs(x);
        }
    }
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;

        arr[u].push_back(v);
        arr[v].push_back(u);
    }

    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if(visited[i] == 0) {
            visited[i] = 1;
            dfs(i);
            cnt++;
        }
    }

    cout << cnt;
}