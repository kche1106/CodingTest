//
//  10026.cpp
//  DataStructure
//
//  Created by 김채은 on 2023/04/08.
//

#include <iostream>
using namespace std;

bool visited[1000000];
int arr[5][5], result = 0;
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

void DFS(int a, int b, int cnt, int num) {
    
    if(cnt == 5) {
        if(visited[num] == false) {
            visited[num] = true;
            result += 1;
       }
        return;
    }
    
    for(int i = 0; i < 4; i++) {
        int nx = a + dx[i];
        int ny = b + dy[i];

        if (nx >= 0 && ny >= 0 && nx < 5 && ny < 5)
        {
            DFS(nx, ny, cnt+1, num * 10 + arr[nx][ny]);
        }
    }
}

int main() {
    
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            cin >> arr[i][j];
        }
    }
    
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            DFS(i,j,0, arr[i][j]);
        }
    }
    
    cout << result;
}
