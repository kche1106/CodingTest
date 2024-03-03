//
//  15663.cpp
//  DataStructure
//
//  Created by 김채은 on 2024/03/03.
//

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <set>
using namespace std;

int n, m;
int arr[9];
int res[9];
int visited[10001];
set<string> sres;

void dfs(int l, int cnt) {
    if(cnt == m) {
        string tmp = "";
        for(int i = 0; i < m; i++) {
            tmp += to_string(res[i]) + " ";
        }
        if(sres.find(tmp) == sres.end()) {
            sres.insert(tmp);
            for(int i = 0; i < m; i++) {
                cout << res[i] << " ";
            }
            cout << "\n";
        }
        return;
    }
    
    for(int i = 0; i < n; i++) {
        int num = arr[i];
        if(!visited[i]) {
            visited[i] = 1;
            res[cnt] = num;
            dfs(i, cnt+1);
            visited[i] = 0;
        }
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
