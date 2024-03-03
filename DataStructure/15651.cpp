//
//  15651.cpp
//  DataStructure
//
//  Created by 김채은 on 2024/03/02.
//

#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<int> v;

void dfs(int num) {
    if(v.size() == m) {
        for(int i = 0; i < v.size(); i++) cout << v[i] << " ";
        cout << '\n';
        return;
    }
    
    for(int i = 1; i <= n; i++) {
        v.push_back(i);
        dfs(i);
        v.erase(v.end()-1);
    }
}

int main() {
    cin >> n >> m;
    
    for(int i = 1; i <= n; i++) {
        v.push_back(i);
        dfs(i);
        v.clear();
    }
}
