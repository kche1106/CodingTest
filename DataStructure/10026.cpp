//
//  10026.cpp
//  DataStructure
//
//  Created by 김채은 on 2023/10/25.
//

#include <iostream>
#include <string>
using namespace std;

int n;
char colors[101][101];
int dx[] = {-1,0,1,0};
int dy[] = {0,-1,0,1};
int isVisited[101][101];

void DFS1(int x, int y) {
    isVisited[x][y] = 1;
    
    for(int i = 0; i < 4; i++) {
        int rx = x + dx[i];
        int ry = y + dy[i];
        
        if(rx < 0 || rx >= n || ry < 0 || ry >= n) continue;
        if(isVisited[rx][ry] || colors[x][y] != colors[rx][ry]) continue;
        DFS1(rx, ry);
    }
}

void DFS2(int x, int y) {
    isVisited[x][y] = 1;
    
    for(int i = 0; i < 4; i++) {
        int rx = x + dx[i];
        int ry = y + dy[i];
        
        if(rx < 0 || rx >= n || ry < 0 || ry >= n) continue;
        if(isVisited[rx][ry]) continue;
            
        if((colors[x][y] == 'G' && colors[rx][ry] == 'R') ||
           (colors[x][y] == 'R' && colors[rx][ry] == 'G')) DFS2(rx, ry);
        if(colors[x][y] == colors[rx][ry]) DFS2(rx, ry);
        
    }
}

int main() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        string color;
        cin >> color;
        for(int j = 0; j < color.size(); j++) {
            colors[i][j] = color[j];
        }
    }
    
    int cnt1 = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(!isVisited[i][j]) {
                isVisited[i][j] = 1;
                cnt1++;
                DFS1(i, j);
            }
        }
    }
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            isVisited[i][j] = 0;
        }
    }
    
    int cnt2 = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(!isVisited[i][j]) {
                isVisited[i][j] = 1;
                cnt2++;
                DFS2(i, j);
            }
        }
    }
    
    cout << cnt1 << " " << cnt2 << endl;
}
