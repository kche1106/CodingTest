//
//  1715.cpp
//  DataStructure
//
//  Created by ±Ë√§¿∫ on 2024/02/26.
//

#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int n, m;
int map[201][201];
int visited[201];
bool res = false;

void dfs(int v) {
	visited[v] = 1;
	
	for (int i = 1; i <= n; i++) {
		if (map[v][i] && !visited[i]) {
			visited[i] = 1;
			dfs(i);
		}
	}
}

int main() {
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> map[i][j];
		}
	}

	int plan[1001];
	for (int i = 0; i < m; i++) {
		cin >> plan[i];
	}

	dfs(plan[0]);
	bool res = true;
	for (int i = 0; i < m; i++) {
		if (visited[plan[i]] == 0) res = false;
	}

	if (res) cout << "YES";
	else cout << "NO";
}