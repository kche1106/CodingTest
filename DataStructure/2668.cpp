//
//  2668.cpp
//  DataStructure
//
//  Created by 김채은 on 2024/03/12.
//

#include <iostream>
#include <set>
#include <cstring>
using namespace std;

int n;
int visited[101];
int arr[101];
bool flag;
set<int> ans;

void dfs(int s, int e) {
    if(visited[s]) {
        if(s == e) {
            flag = true;
            ans.insert(s);
        }
        return;
    }
    
    visited[s] = 1;
    dfs(arr[s], e);
    if(flag) {
        ans.insert(s);
        ans.insert(e);
    }
}

int main() {
    cin >> n;
    
    for(int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    
    for(int i = 1; i <= n; i++) {
        visited[i] = 1;
        dfs(arr[i], i);
        memset(visited, 0, sizeof(visited));
        flag = false;
    }
    
    cout << ans.size() << "\n";
    for(auto a : ans) cout << a << "\n";
}
