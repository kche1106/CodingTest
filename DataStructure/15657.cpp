//
//  15657.cpp
//  DataStructure
//
//  Created by 김채은 on 2024/03/03.
//

#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int arr[9];
int res[9];

void dfs(int l, int cnt) {
    if(cnt == m) {
        for(int i = 0; i < m; i++) cout << res[i] << " ";
        cout << "\n";
        return;
    }
    
    for(int i = l; i < n; i++) {
        res[cnt] = arr[i];
        dfs(i, cnt+1);
    }
}


int main() {
    cin >> n >> m;
    
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr, arr+n);
    
    dfs(0, 0);
}
