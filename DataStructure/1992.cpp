//
//  1992.cpp
//  DataStructure
//
//  Created by 김채은 on 2022/10/02.
//

#include <iostream>
#include <string>
using namespace std;

string arr[64];
char v[64][64];

void func(int size, int x, int y) {
    
    
    for(int i = y; i < y + size; i++) {
        for(int j = x; j < x + size; j++) {
            char c = v[y][x];
            if(v[i][j] != c) {
                cout << "(";
                func(size / 2, x, y);  //왼쪽 위
                func(size / 2, x + size / 2, y);  //오른쪽 위
                func(size / 2, x, y + size / 2);  //왼쪽 아래
                func(size / 2, x + size / 2, y + size / 2);  //오른쪽 아래
                cout << ")";
                return;
            }
        }
    }

    cout << v[y][x];
}

int main() {
    int n;
    cin >> n;
    
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
        for(int j = 0; j < n; j++) {
            v[i][j] = arr[i].at(j);
        }
    }
    
    func(n, 0, 0);
}
