//
//  1149.cpp
//  DataStructure
//
//  Created by 김채은 on 2023/10/27.
//

#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    int house[n][3];
    for(int i = 0; i < n; i++) {
        cin >> house[i][0] >> house[i][1] >> house[i][2];
    }
    
    int dy[n][3];
    dy[0][0] = house[0][0]; dy[0][1] = house[0][1]; dy[0][2] = house[0][2];
    for(int i = 1; i < n; i++) {
        dy[i][0] = house[i][0] + min(dy[i-1][1], dy[i-1][2]);
        dy[i][1] = house[i][1] + min(dy[i-1][0], dy[i-1][2]);
        dy[i][2] = house[i][2] + min(dy[i-1][0], dy[i-1][1]);
    }
    
    cout << min(dy[n-1][0], min(dy[n-1][1], dy[n-1][2]));
}
