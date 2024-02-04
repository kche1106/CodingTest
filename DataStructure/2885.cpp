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
    
    int size = 1;
    while(size < k) {
        size *= 2;
    }
    
    cout << size << " ";
    
    int cnt = 0;
    while(size > 0) {
        if(k % size == 0) {
            cout << cnt << endl;
            break;
        }
        else {
            size /= 2;
            cnt++;
        }
    }
}
