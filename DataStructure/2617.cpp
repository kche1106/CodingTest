//
//  2617.cpp
//  DataStructure
//
//  Created by 김채은 on 2024/02/11.
//

#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int visited[100];

int main() {
    int n, m;
    cin >> n >> m;
    
    int mid = (n + 1) / 2;
    
    vector<int> heavy[100];
    vector<int> light[100];
    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        heavy[a].push_back(b);
        light[b].push_back(a);
    }
    
    int res = 0;
    for(int i = 1; i <= n; i++) {
        queue<int> q;
        q.push(i);
        visited[i] = 1;
        
        int cnt = 0;
        while(!q.empty()) {
            int x = q.front();
            q.pop();
            
            for(int j = 0; j < heavy[x].size(); j++) {
                int nx = heavy[x][j];
                
                if(!visited[nx]) {
                    cnt++;
                    visited[nx] = 1;
                    q.push(nx);
                }
            }
        }
        
        memset(visited, 0, sizeof(visited));
        if(cnt >= mid) res++;
    }
    
    
    for(int i = 1; i <= n; i++) {
        queue<int> q;
        q.push(i);
        visited[i] = 1;
        
        int cnt = 0;
        while(!q.empty()) {
            int x = q.front();
            q.pop();
            
            for(int j = 0; j < light[x].size(); j++) {
                int nx = light[x][j];
                if(!visited[nx]) {
                    cnt++;
                    visited[nx] = 1;
                    q.push(nx);
                }
            }
        }
        
        memset(visited, 0, sizeof(visited));
        if(cnt >= mid) res++;
    }
    
    cout << res;
}

/*
 5 4
 2 1
 4 3
 5 1
 4 2
 */
