//
//  6283.cpp
//  softeer
//
//  Created by 김채은 on 2024/03/08.
//

#include <iostream>
using namespace std;

int main() {
    int arr[9];
    for(int i = 1; i <= 8; i++) {
        cin >> arr[i];
    }
    
    bool asc = true;
    for(int i = 1; i < 8; i++) {
        if(arr[i] != i) asc = false;
    }
    
    if(!asc) {
        bool dsc = true;
        for(int i = 8; i >= 1; i--) {
            if(arr[i] != (9-i)) dsc = false;
        }
        
        if(!dsc) cout << "mixed";
        else cout << "descending";
    }
    else cout << "ascending";
}
