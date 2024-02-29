//
//  2847.cpp
//  DataStructure
//
//  Created by 김채은 on 2024/02/29.
//

#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    int score[101];
    for(int i = 0; i < n; i++) {
        cin >> score[i];
    }
    
    int res = 0;
    for(int i = n-2; i >= 0; i--) {
        while(score[i] >= score[i+1]) {
            res++;
            score[i]--;
        }
    }
    
    cout << res;
}
