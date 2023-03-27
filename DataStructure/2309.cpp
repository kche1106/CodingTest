//
//  2309.cpp
//  DataStructure
//
//  Created by 김채은 on 2023/03/27.
//

#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int height[9];
    int sum = 0;
    
    for(int i = 0; i < 9; i++) {
        cin >> height[i];
        sum += height[i];
    }
    
    int idx1 = 0, idx2 = 0;
    int total = 0;
    int cnt = 0;
    for(int i = 0; i < 9; i++) {
        for(int j = 0; j < 9; j++) {
            if(i == j) break;
            
            total = sum - height[i] - height[j];
            if(total == 100) {
                idx1 = i;
                idx2 = j;
                cnt ++;
                break;
            }
        }
        if(cnt >= 1)
            break;
    }
    
    height[idx1] = 100;
    height[idx2] = 100;
    
    sort(height, height + 9);
    
    for(int i = 0; i < 7; i++) {
        cout << height[i] << endl;
    }
}
