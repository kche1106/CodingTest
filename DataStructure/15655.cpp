//
//  15655.cpp
//  DataStructure
//
//  Created by 김채은 on 2024/03/03.
//

#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int arr[9];
int visited[10001];
int res[9];

void dfs(int cnt) {
    if(cnt == m) {
        for(int i = 0; i < m; i++) cout << res[i] << " ";
        cout << '\n';
        return;
    }
    
    for(int i = 0; i < n; i++) {
        int num = arr[i];
        
        if(!visited[num]) {
            if(cnt == 0) {
                visited[num] = 1;
                res[cnt] = num;
                dfs(cnt+1);
                visited[num] = 0;
            }
            else if(res[cnt-1] < num) {
                res[cnt] = num;
                dfs(cnt+1);
                visited[num] = 0;
            }
        }
    }
}

int main() {
    cin >> n >> m;
    
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr, arr+n);
    dfs(0);
}
