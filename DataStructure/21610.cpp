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
int cloud[51][51];
vector<pair<int, int>> cloudv;
int a[51][51];
int dx[] = {0, -1, -1, -1, 0, 1, 1, 1};
int dy[] = {-1, -1, 0, 1, 1, 1, 0, -1};

void move(int d, int s) {
    
    memset(cloud, 0, sizeof(cloud));
    for(int i = 0; i < cloudv.size(); i++) {
        int x = cloudv[i].first;
        int y = cloudv[i].second;
        
        int nx = x;
        int ny = y;
        for(int j = 0; j < s; j++) {
            nx += dx[d];
            ny += dy[d];
            
            if(nx > n) nx = 1;
            if(nx < 1) nx = n;
            if(ny > n) ny = 1;
            if(ny < 1) ny = n;
        }
        cloudv[i].first = nx;
        cloudv[i].second = ny;
        cloud[nx][ny] = 1;
    }
}

void rain() {
    for(int i = 0; i < cloudv.size(); i++) {
        int x = cloudv[i].first;
        int y = cloudv[i].second;
        a[x][y] ++;
    }
}

void copy() {
    for(int i = 0; i < cloudv.size(); i++) {
        int x = cloudv[i].first;
        int y = cloudv[i].second;
        
        int cnt = 0;
        for(int j = 1; j < 8; j+=2) {
            int nx = x + dx[j];
            int ny = y + dy[j];
            if(nx < 1 || nx > n || ny < 1 || ny > n) continue;
            if(a[nx][ny] >= 1) cnt++;
        }
        
        a[x][y] += cnt;
    }
}

void newcloud() {
    
    cloudv.clear();
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(cloud[i][j] == 0 && a[i][j] >= 2) {
                a[i][j] -= 2;
                cloudv.push_back({i, j});
            }
        }
    }
    
    memset(cloud, 0, sizeof(cloud));
    for(int i = 0; i < cloudv.size(); i++) {
        int x = cloudv[i].first;
        int y = cloudv[i].second;
        
        cloud[x][y] = 1;
    }
}

int main() {
    cin >> n >> m;

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }
    
    int d[101], s[101];
    for(int i = 0; i < m; i++) {
        cin >> d[i] >> s[i];
    }
    
    //초기 구름
    cloud[n][1] = 1;
    cloud[n][2] = 1;
    cloud[n-1][1] = 1;
    cloud[n-1][2] = 1;
    cloudv.push_back({n, 1});
    cloudv.push_back({n, 2});
    cloudv.push_back({n-1, 1});
    cloudv.push_back({n-1, 2});
    
    for(int i = 0; i < m; i++) {
        move(d[i]-1, s[i]);
        rain();
        copy();
        newcloud();
    }
    
    int res = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            res += a[i][j];
        }
    }
    
    cout << res << endl;
}
