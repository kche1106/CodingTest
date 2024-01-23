//
//  9372.cpp
//  DataStructure
//
//  Created by 김채은 on 2024/01/23.
//

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
    int t;
    cin >> t;
    
    for(int i = 0; i < t; i++) {
        int n, m;
        cin >> n >> m;  //국가 수, 비행기 종류
        
        for(int j = 0; j < m; j++) {
            int a, b;
            cin >> a >> b;
        }
        
        cout << n - 1 << endl;
    }
}
