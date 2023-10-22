//
//  2667.cpp
//  DataStructure
//
//  Created by 김채은 on 2023/10/21.
//

#include <iostream>
#include <algorithm>
using namespace std;

int n;
string house[26][26];
int isVisited[26][26];
int sum, res = 0;
vector<int> ans;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

void DFS(int x, int y) {
    
    for(int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        
        if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
        
        if(!isVisited[nx][ny] && house[nx][ny] == "1") {
            isVisited[nx][ny] = 1;
            sum++;
            DFS(nx, ny);
        }
        
    }
}

int main() {
    cin >> n;
    
    for(int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for(int j = 0; j < s.length(); j++) {
            house[i][j] = s[j];
        }
    }
    
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(!isVisited[i][j] && house[i][j] == "1") {
                isVisited[i][j] = 1;
                sum = 1;
                DFS(i, j);
                ans.push_back(sum);
                res++;
            }
        }
    }
    
    sort(ans.begin(), ans.end());
    
    cout << res << endl;
    
    for(int j = 0; j < ans.size(); j++) {
        cout << ans[j] << endl;
    }
}
