//
//  1240.cpp
//  DataStructure
//
//  Created by 김채은 on 2024/02/11.
//

#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int n, m;
//int tree[1010][1010];
vector<pair<int, int>> tree[1010];
int x, y;
queue<pair<int, int>> q;
int visited[1010];
int res;

void bfs()
{

    res = 0;
    while (!q.empty())
    {
        int node = q.front().first;
        int dist = q.front().second;
        q.pop();

        // cout << "node = " << node << " dist = " << dist << endl;

        if (node == y) {
            res = dist;
        }

        for (int i = 0; i < tree[node].size(); i++) {
            int nx = tree[node][i].first;
            int ndist = tree[node][i].second;

            if (!visited[nx])
            {
                visited[nx] = 1;
                q.push({nx, dist + ndist});
            }
        }
    }

}

int main() {
    cin >> n >> m;

    int a, b, c;
    for (int i = 0; i < n-1; i++) {
        cin >> a >> b >> c;
        tree[a].push_back({b, c});
        tree[b].push_back({a, c});
    }

    while (m--) {
        cin >> x >> y;
        
        visited[x] = 1;
        q.push({x, 0});
        bfs();

        cout << res << "\n";
        memset(visited, 0, sizeof(visited));
    }
}
