//
//  15656.cpp
//  DataStructure
//
//  Created by 김채은 on 2024/03/03.
//

#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int arr[8];
int res[8];

void dfs(int cnt) {
    if(cnt == m) {
        for(int i = 0; i < m; i++) cout << res[i] << " ";
        cout << "\n";
        return;
    }
    
    for(int i = 0; i < n; i++) {
        int num = arr[i];
        
        res[cnt] = num;
        dfs(cnt+1);
    }
}

int main() {
    cin >> n >> m;
    
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + n);
    
    dfs(0);
}
