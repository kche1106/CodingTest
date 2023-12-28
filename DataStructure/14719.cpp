//
//  14719.cpp
//  DataStructure
//
//  Created by 김채은 on 2023/12/28.
//

#include <iostream>
using namespace std;

int h, w, res;
int world[501];

int main() {
    cin >> h >> w;
    
    for(int i = 0; i < w; i++) {
        cin >> world[i];
    }
    
    for(int i = 1; i < w; i++) {
        int max_l = 0, max_r = 0;
        
        for(int j = 0; j < i; j++) {
            if(max_l < world[j]) max_l = world[j];
        }
        
        for(int j = i+1; j < w; j++) {
            if(max_r < world[j]) max_r = world[j];
        }
        
        int tmp = min(max_l, max_r) - world[i];  // 내가 현재 있는 위치가 왼, 오른쪽 블록보다 높이 있으면 음수값이 나옴
        if(tmp > 0) res += tmp;
        
    }
    
    cout << res << endl;
}
