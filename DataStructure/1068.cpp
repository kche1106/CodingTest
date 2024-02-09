//
//  1068.cpp
//  DataStructure
//
//  Created by 김채은 on 2024/02/09.
//

#include <iostream>
#include <vector>
using namespace std;

vector<int> v[51];
int visited[51];
int rm;
int res;

void DFS(int node) {
    if(v[node].size() == 1 && v[node][0] == rm) {
        res++;
        return;
    }
    
    if(v[node].size() == 0) {
        res++;
        return;
    }
    
    for(int i = 0; i < v[node].size(); i++) {
        int next = v[node][i];
        if(visited[next] == 0 && next != rm) {
            visited[next] = 1;
            DFS(next);
        }
    }
}

int main() {
    int n;
    cin >> n;
    
    int root = 0;
    for(int i = 0; i < n; i++) {
        int a;
        cin >> a;
        if(a == -1) root = i;
        else v[a].push_back(i);
    }
    
    cin >> rm;
    
    if(rm != root) {
        visited[root] = 1;
        DFS(root);
    }
    
    cout << res;
}
