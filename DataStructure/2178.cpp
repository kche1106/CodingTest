//
//  2178.cpp
//  DataStructure
//
//  Created by 김채은 on 2024/01/04.
//

#include <iostream>
#include <queue>
using namespace std;

int arr[101][101], dist[101][101];
queue<pair<int, int>> q;
int n, m;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};


void BFS() {
    
    while(!q.empty()) {
        
        int qx = q.front().first;
        int qy = q.front().second;
        
        q.pop();
        
        for(int i = 0; i < 4; i++) {
            int nx = qx + dx[i];
            int ny = qy + dy[i];
            
            if(nx >= 0 && nx < n && ny >= 0 && ny < m) {
                if(arr[nx][ny] == 1 && dist[nx][ny] == 0) {
                    q.push(make_pair(nx, ny));
                    dist[nx][ny] = dist[qx][qy] + 1;
                }
            }
        }
    }
    
}

int main() {
    cin >> n >> m;
    
//    for(int i = 0; i < n; i++) {
//        int num;
//        cin >> num;
//        for(int j = m-1; j >= 0; j--) {
//            arr[i][j] = num % 10;
//            num /= 10;
//        }
//    }
    
    for (int i = 0; i < n; i++) {
        string temp;
        cin >> temp;
        for (int j = 0; j < m; j++) {
            arr[i][j] = temp[j] - '0';
        }
    }
        
    q.push(make_pair(0,0));
    dist[0][0] = 1;
    BFS();
    
    cout << dist[n-1][m-1] << endl;
}
