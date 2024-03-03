//
//  15652.cpp
//  DataStructure
//
//  Created by 김채은 on 2024/03/02.
//

#include <iostream>
#include <vector>
using namespace std;

int n, m;
//vector<int> v;
int visited[9];
int res[9];

void dfs(int cnt) {
//    if(v.size() == m) {
//        for(int i = 0; i < m; i++) cout << v[i] << " ";
//        cout << '\n';
//        return;
//    }
    
    if(cnt == m) {
        for(int i = 0; i < m; i++) cout << res[i] << " ";
        cout << endl;
        return;
    }
    
//    for(int i = num; i <= n; i++) {
//        v.push_back(i);
//        dfs(i);
//        v.erase(v.end()-1);
//    }
    
    for(int i = 1; i <= n; i++) {
        if(cnt == 0) res[cnt] = i;
        if(res[cnt-1] <= i) {
            res[cnt] = i;
            dfs(cnt+1);
        }
        
    }
}

int main() {
    cin >> n >> m;
//    for(int i = 1; i <= n; i++) {
//        v.push_back(i);
//        dfs(i);
//        v.clear();
//    }
    
    dfs(0);
}
