//
//  2839.cpp
//  DataStructure
//
//  Created by 김채은 on 2023/12/14.
//

#include <iostream>
using namespace std;


int main() {
    int n;
    cin >> n;
    
    int dy[5000];
    
    for(int i = 0; i <= n; i++) {
        dy[i] = -1;
    }

    dy[3] = 1; dy[5] = 1;
    
    for(int i = 6; i <= n; i++) {
        if(dy[i-3] != -1) {
            dy[i] = dy[i-3] + 1;
        }
        if(dy[i-5] != -1) {
            if(dy[i] == -1) dy[i] = dy[i-5] + 1;
            else if(dy[i] > dy[i-5] + 1) dy[i] = dy[i-5] + 1;
        }
    }

    cout << dy[n] << endl;
}
