//
//  2805.cpp
//  SWEA
//
//  Created by 김채은 on 2023/11/01.
//

#include <iostream>
#include <string>
using namespace std;

int main() {
    int t;
    cin >> t;
    
    for(int i = 1; i <= t; i++) {
        
        int n, w[49][49], res = 0;
        cin >> n;
        
        for(int i = 0; i < n; i++) {
            string s;
            cin >> s;
            for(int j = 0; j < n; j++) {
                w[i][j] = s[j] - '0';
            }
        }
        
        for(int i = 0; i < n/2 + 1; i++) {
            for(int j = (n/2 - i); j <= (n/2 + i); j++) {
                res += w[i][j];
            }
        }
        
        for(int i = n/2 + 1; i < n; i++) {
            for(int j = (i - n/2); j <= (3 * n/2 - i - 1); j++) {
                res += w[i][j];
            }
        }
        
        cout << "#" << i << " " << res << endl;
    }
}
