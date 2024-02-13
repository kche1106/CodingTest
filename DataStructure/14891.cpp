//
//  14891.cpp
//  DataStructure
//
//  Created by 김채은 on 2024/02/03.
//

#include <iostream>
#include <deque>
#include <cstring>
using namespace std;

deque<int> tob[5];
int dir[5];
int check[5];

void rotation() {
    for(int i = 1; i <= 4; i++) {
        if(dir[i] == 0) continue;
        else if(dir[i] == 1) {  //시계방향
            tob[i].push_front(tob[i].back());
            tob[i].pop_back();
        }
        else if(dir[i] == -1) {  //반시계방향
            tob[i].push_back(tob[i].front());
            tob[i].pop_front();
        }
    }
}

void direction(int n, int d) {
    dir[n] = d;
    check[n] = 1;
    
    if(n-1 > 0 && check[n-1] == 0) {
        if(d == 0) direction(n-1, 0);
        else if(tob[n-1][2] != tob[n][6]) {
            direction(n-1, -d);
        }
        else direction(n-1, 0);
    }
    
    if(n+1 <= 4 && check[n+1] == 0) {
        if(d == 0) direction(n+1, 0);
        else if(tob[n+1][6] != tob[n][2]) {
            direction(n+1, -d);
        }
        else direction(n+1, 0);
    }
    
}

int main() {
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 8; j++) {
            char c;
            cin >> c;
            tob[i+1].push_back(c - '0');
        }
    }
    
    int k;
    cin >> k;
    
    while(k--) {
        int n, dir;
        cin >> n >> dir;
        
        direction(n, dir);
        rotation();
        memset(check, 0, sizeof(check));
    }
    
    int res = 0;
    if(tob[1][0] == 1) res += 1;
    if(tob[2][0] == 1) res += 2;
    if(tob[3][0] == 1) res += 4;
    if(tob[4][0] == 1) res += 8;
    
    cout << res;
}
