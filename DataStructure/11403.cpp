//
//  11403.cpp
//  DataStructure
//
//  Created by 김채은 on 2024/01/21.
//

#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    int map[100][100];
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> map[i][j];
        }
    }
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            for(int k = 0; k < n; k++) {
                if(map[j][i] == 1 && map[i][k] == 1) map[j][k] = 1;
            }
        }
    }
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout <<  map[i][j] << " ";
        }
        cout << endl;
    }
}
