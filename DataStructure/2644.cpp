//
//  2644.cpp
//  DataStructure
//
//  Created by 김채은 on 2024/02/03.
//

#include <iostream>
#include <queue>
using namespace std;

int family[100][100];
int visited[100];

int main() {
    int n;
    cin >> n;
    
    int a, b;
    cin >> a >> b;
    
    int m;
    cin >> m;
    
    for(int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        family[x][y] = 1;
        family[y][x] = 1;
    }
    
    queue<int> q;
    q.push(a);
    
    while(!q.empty()) {
        int qx = q.front();
        q.pop();
        
        for(int i = 1; i <= n; i++) {
            if(family[qx][i] == 1 && visited[i] == 0) {
                visited[i] = visited[qx] + 1;
                q.push(i);
            }
        }
    }
    
    if(visited[b] == 0) visited[b] = -1;
    
    
    cout << visited[b];
}
