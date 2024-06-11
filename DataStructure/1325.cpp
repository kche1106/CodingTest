#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

int n, m;
vector<int> com[10001];
int cnt;
int visited[10001];

void dfs(int l) { 
    cnt++;
    //cout << "l = " << l << endl;
    for (int i = 0; i < com[l].size(); i++) {
        int x = com[l][i];
        if (!visited[x]) {
            // cnt++;
            visited[x] = 1;
            dfs(x);
        }
    }
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;

        com[b].push_back(a);
    }

    int res[10001];
    int max = 0;
    for (int i = 1; i <= n; i++) {
        visited[i] = 1;
        dfs(i);
        res[i] = cnt;
        if(max < cnt)
            max = cnt;
        cnt = 0;
        memset(visited, 0, sizeof(visited));
    }

    for (int i = 1; i <= n; i++) {
        if(res[i] == max)
            cout << i << " ";
    }
}