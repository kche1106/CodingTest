//
//  21610.cpp
//  DataStructure
//
//  Created by 김채은 on 2024/02/04.
//

#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int n, m;
int cloud_map[51][51];
vector<pair<int, int>> cloud;
int a[51][51];
int dx[] = {0, -1, -1, -1, 0, 1, 1, 1};
int dy[] = {-1, -1, 0, 1, 1, 1, 0, -1};

void move(int d, int s) {
    memset(cloud_map, 0, sizeof(cloud_map));
    for(int i = 0; i < cloud.size(); i++) {
        int x = cloud[i].first;
        int y = cloud[i].second;
        
        int nx = x;
        int ny = y;
        for(int j = 0; j < s; j++) {
            nx += dx[d];
            ny += dy[d];
            if(nx > n) nx = 1;
            if(ny > n) ny = 1;
            if(nx < 1) nx = n;
            if(ny < 1) ny = n;
        }
        cloud_map[nx][ny] = 1;
        cloud[i].first = nx;
        cloud[i].second = ny;
    }
}

void rain() {
    for(int i = 0; i < cloud.size(); i++) {
        int x = cloud[i].first;
        int y = cloud[i].second;
        a[x][y] += 1;
    }
}

void add() {
    for(int i = 0; i < cloud.size(); i++) {
        int x = cloud[i].first;
        int y = cloud[i].second;
        
        int cnt = 0;
        for(int d = 1; d < 8; d+=2) {
            int nx = x + dx[d];
            int ny = y + dy[d];
            if(nx < 1 || nx > n || ny < 1 || ny > n) continue;
            if(a[nx][ny] > 0) cnt++;
        }
        a[x][y] += cnt;
    }
}

void makecloud() {
    
    cloud.clear();
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(cloud_map[i][j] == 1) continue;
            
            if(a[i][j] >= 2) {
                cloud.push_back({i, j}) ;
                a[i][j] -= 2;
            }
        }
    }
    
    memset(cloud_map, 0, sizeof(cloud_map));
    for(int i = 0; i <= cloud.size(); i++) {
        cloud_map[cloud[i].first][cloud[i].second] = 1;
    }
}

int main() {
    cin >> n >> m;
    
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }
    
    cloud_map[n][1] = 1;
    cloud_map[n][2] = 1;
    cloud_map[n-1][1] = 1;
    cloud_map[n-1][2] = 1;
    cloud.push_back({n, 1});
    cloud.push_back({n, 2});
    cloud.push_back({n-1, 1});
    cloud.push_back({n-1, 2});
    
    
    for(int i = 0; i < m; i++) {
        int d, s;
        cin >> d >> s;
        
        move(d-1, s);
        rain();
        add();
        makecloud();
    }
    
    int res = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            res += a[i][j];
        }
    }
    
    cout << res;
}
