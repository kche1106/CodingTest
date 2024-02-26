//
//  1717.cpp
//  DataStructure
//
//  Created by 김채은 on 2024/02/25.
//

#include <iostream>
#include <vector>
using namespace std;

int arr[1000001];

int Find(int v) {
    if(v == arr[v]) return v;
    else {
        arr[v] = Find(arr[v]);
        return arr[v];
    }
}

void Union(int a, int b) {
    a = Find(a);
    b = Find(b);
    if(a != b) arr[a] = b;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int n, m;
    cin >> n >> m;
    
    for(int i = 0; i <= n; i++) {
        arr[i] = i;
    }
    
    for(int i = 0; i < m; i++) {
        int x, a, b;
        cin >> x >> a >> b;
        
        if(x == 0) Union(a, b);
        else if(x == 1) {
            int r1 = Find(a);
            int r2 = Find(b);
            if(r1 == r2) cout << "YES\n";
            else cout << "NO\n";
        }
    }
}
