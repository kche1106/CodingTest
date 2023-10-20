//
//  2606.cpp
//  DataStructure
//
//  Created by 김채은 on 2023/10/20.
//

#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<int> v[10000];
bool isVisit[100];

void DFS(int x) {
    isVisit[x] = true;
    for(int i = 0; i < v[x].size(); i++) {
        if(!isVisit[v[x][i]]) {
            DFS(v[x][i]);
        }
    }
}

int main() {
    cin >> n >> m;
    
    int a, b;
    for(int i = 1; i <= m; i++) {
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    
    for(int i = 0; i < n; i++) {
        isVisit[i] = 0;
    }
    DFS(1);
    
    int cnt = 0;
    for(int i = 2; i <= n; i++) {
        if(isVisit[i] == true) cnt++;
    }
    
    cout << cnt << endl;
}
