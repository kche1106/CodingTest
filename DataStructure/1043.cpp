//
//  1043.cpp
//  DataStructure
//
//  Created by 김채은 on 2024/02/12.
//

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;  //사람, 파티

	int t_num;
	cin >> t_num;

	vector<int> truth;
	for (int i = 0; i < t_num; i++) {
		int a;
		cin >> a;
		truth.push_back(a);
	}

	vector<int> party[50];
	vector<int> people[50];
	for (int i = 0; i < m; i++) {
		int num;
		cin >> num;

		for (int j = 0; j < num; j++) {
			int x;
			cin >> x;
			party[i].push_back(x);
			people[x].push_back(i);
		}
	}

	int res[50];
	for (int i = 0; i < m; i++) {
		res[i] = 1;
	}
	int visited[50];
	memset(visited, 0, sizeof(visited));
	for (int i = 0; i < truth.size(); i++) {
		int t = truth[i];
		visited[t] = 1;
		for (int j = 0; j < people[t].size(); j++) {
			int p = people[t][j];  //party
			if (res[p] == 0) continue;
			res[p] = 0;

			for (int k = 0; k < party[p].size(); k++) {
				int m = party[p][k];
				if (visited[m]) continue;
				truth.push_back(m);
				visited[m] = 1;
			}
		}
	}

	int cnt = 0;
	for (int i = 0; i < m; i++) {
		/*cout << res[i] << " ";*/
		if (res[i] == 1) cnt++;
	}

	cout << cnt;

}