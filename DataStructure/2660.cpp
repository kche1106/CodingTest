//
//  2660.cpp
//  DataStructure
//
//  Created by 김채은 on 2024/01/21.
//

#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    int map[50][50];
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            map[i][j] = 100;
        }
    }
    
    for(int i = 1; i <= n; i++) map[i][i] = 0;
    
    while (true) {
        int a, b;
        cin >> a >> b;
        if(a == -1 && b == -1) break;
        map[a][b] = 1;
        map[b][a] = 1;
    }
    
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            for(int k = 1; k <= n; k++) {
                if(map[j][i] != 100 && map[i][k] != 100)
                    map[j][k] = min(map[j][k], map[j][i] + map[i][k]);
            }
        }
    }
    
    int arr[50];
    for(int i = 1; i <= n; i++) {
        int tmp = 0;
        for(int j = 1; j <= n; j++) {
            if(tmp < map[i][j]) tmp = map[i][j];
        }
        arr[i] = tmp;
    }
    
    int boss = 100, cnt = 0;
    for(int i = 1; i <= n; i++) {
        if(boss > arr[i]) boss = arr[i];
    }
    
    for(int i = 1; i <= n; i++) {
        if(boss == arr[i]) cnt++;
    }
    
    cout << boss << " " << cnt << endl;
    
    for(int i = 1; i <= n; i++) {
        if(boss == arr[i]) cout << i << " ";
    }
}
