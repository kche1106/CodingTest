//
//  11724.cpp
//  DataStructure
//
//  Created by 김채은 on 2023/10/21.
//

#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<int> vec[1001];
int isVisit[1001];

void DFS(int x) {
    isVisit[x] = 1;
    for(int i = 0; i < vec[x].size(); i++) {
        if(!isVisit[vec[x][i]]) DFS(vec[x][i]);
    }
}

int main() {
    cin >> N >> M;
    
    int u, v;
    for(int i = 1; i <= M; i++) {
        cin >> u >> v;
        vec[u].push_back(v);
        vec[v].push_back(u);
    }
    
    int cnt = 0;
    for(int i = 1; i <= N; i++) {
        if(!isVisit[i]){
            cnt++;
            DFS(i);
        }
    }
    
    cout << cnt << endl;
}
