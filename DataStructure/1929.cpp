//
//  1929.cpp
//  DataStructure
//
//  Created by 김채은 on 2024/01/22.
//

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int m, n;
    cin >> m >> n;
    
    vector<int> arr(n+1, 0);
    for(int i = 2; i <= n; i++) {
        arr[i] = i;
    }
    
    for(int i = 2; i*i <= n; i++) {
        if(arr[i] == 0) continue;
        for(int j = 2 * i; j <= n; j += i) {
            if(arr[j] == 0) continue;
            else arr[j] = 0;
        }
    }
    
    for(int i = m; i <= n; i++) {
        if(arr[i] != 0) cout << arr[i] << '\n';
    }
}
