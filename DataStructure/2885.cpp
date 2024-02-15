//
//  2885.cpp
//  DataStructure
//
//  Created by 김채은 on 2024/02/04.
//

#include <iostream>
using namespace std;

int main() {
    int k;
    cin >> k;
    
    int choco = 1;
    while (true) {
        if(k <= choco) break;
        choco *= 2;
    }
    
    cout << choco << " ";
    
    int cnt = 0;
    while (true) {
        if(k % choco == 0) {
            cout << cnt;
            break;
        }
        else {
            cnt++;
            choco /= 2;
        }
    }
}
