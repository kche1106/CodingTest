//
//  17276.cpp
//  DataStructure
//
//  Created by 김채은 on 2024/03/18.
//

#include <iostream>
#include <memory.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, d;
        cin >> n >> d;
        
        int map[501][501];
        int res[501][501];
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                cin >> map[i][j];
            }
        }
        memcpy(res, map, sizeof(res));
        
        int cnt = abs(d)/45;
        if(d > 0) {
            while(cnt--) {
                for(int i = 1; i <= n; i++) res[i][(n+1)/2] = map[i][i];
                for(int i = 1; i <= n; i++) res[i][n+1-i] = map[i][(n+1)/2];
                for(int i = 1; i <= n; i++) res[(n+1)/2][n+1-i] = map[i][n+1-i];
                for(int i = 1; i <= n; i++) res[n+1-i][n+1-i] = map[(n+1)/2][n+1-i];
                memcpy(map, res, sizeof(map));
            }
        }
        else {
            while(cnt--) {
                for(int i = 1; i <= n; i++) res[(n+1)/2][i] = map[i][i];
                for(int i = 1; i <= n; i++) res[n+1-i][i] = map[(n+1)/2][i];
                for(int i = 1; i <= n; i++) res[n+1-i][(n+1)/2] = map[n+1-i][i];
                for(int i = 1; i <= n; i++) res[n+1-i][n+1-i] = map[n+1-i][(n+1)/2];
                memcpy(map, res, sizeof(map));
            }
        }
        
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                cout << res[i][j] << " ";
            }
            cout << endl;
        }
    }
}
