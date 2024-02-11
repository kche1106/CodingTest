//
//  2617.cpp
//  DataStructure
//
//  Created by 김채은 on 2024/02/11.
//

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m;
vector<int> big[100];
vector<int> small[100];
int visited[100];
int cnt;
int res;

void DFS1(int x) {
    
    cnt++;

    for(int i = 0; i < big[x].size(); i++) {
        if(visited[big[x][i]] == 0) {
            visited[big[x][i]] = 1;
            DFS1(big[x][i]);
        }
    }
}

void DFS2(int x) {
    
    cnt++;
    
    for(int i = 0; i < small[x].size(); i++) {
        if(visited[small[x][i]] == 0) {
            visited[small[x][i]] = 1;
            DFS2(small[x][i]);
        }
    }
}

int main() {
    cin >> n >> m;
    
    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        big[a].push_back(b);
        small[b].push_back(a);
    }
        
    for(int i = 1; i <= n; i++) {
        cnt = 0;
        for(int j = 1; j <= n; j++) {
            visited[j] = 0;
        }
        visited[i] = 1;
        
        DFS1(i);
        if(cnt > (n+1)/2) res++;
    }
    
    for(int i = 1; i <= n; i++) {
        cnt = 0;
        for(int j = 1; j <= n; j++) {
            visited[j] = 0;
        }
        visited[i] = 1;
        
        DFS2(i);
        if(cnt > (n+1)/2) res++;
    }
    
    cout << res;
}
