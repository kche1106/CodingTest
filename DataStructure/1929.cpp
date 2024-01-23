//
//  1929.cpp
//  DataStructure
//
//  Created by 김채은 on 2024/01/22.
//

#include <iostream>
using namespace std;

int main() {
    int m, n;
    cin >> m >> n;
    
    int a[1000000];
    for(int i = 2; i <= n; i++) {
        for(int j = 2; j * i <= n; j++) {
            a[i * j] = 1;
        }
    }
    
    for(int i = m; i < n; i++) {
        if(a[i] != 1) cout << i << '\n';
    }
}
