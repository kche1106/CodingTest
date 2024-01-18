//
//  17829.cpp
//  DataStructure
//
//  Created by 김채은 on 2024/01/18.
//

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int arr[1024][1024];

void func(int x, int y) {
    vector<int> tmp;
    for(int i = x; i < x+2; i++) {
        for(int j = y; j < y+2; j++) {
            tmp.push_back(arr[i][j]);
        }
    }
    sort(tmp.begin(), tmp.end());
    int max = tmp[2];
    
    arr[x/2][y/2] = max;
}

int main() {
    int n;
    cin >> n;
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }
    
    while(true) {
        if(n == 1) {
            cout << arr[0][0] << endl;
            return 0;
        }
        for(int i = 0; i <= n - 2; i+=2) {
            for(int j = 0; j <= n - 2; j+=2) {
                func(i, j);
            }
        }
        n /= 2;
    }
}
