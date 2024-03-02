//
//  15650.cpp
//  DataStructure
//
//  Created by 김채은 on 2024/03/02.
//

#include <iostream>
#include <cstring>
using namespace std;

int n, m;
int visited[9];

void dfs(int num, int len) {
    if(len == m) {
        for(int i = 0; i < 9; i++) {
            if(visited[i] == 1) 
                cout << i << " ";
        }
        cout << endl;
        return;
    }
    
    for(int i = num+1; i <= n; i++) {
        if(!visited[i]) {
            visited[i] = 1;
            dfs(i, len+1);
            visited[i] = 0;
        }
    }
}

int main() {
    cin >> n >> m;
    
    for(int i = 1; i <= n; i++) {
        if(!visited[i]) {
            visited[i] = 1;
            dfs(i, 1);
        }
        memset(visited, 0, sizeof(visited));
    }
}
