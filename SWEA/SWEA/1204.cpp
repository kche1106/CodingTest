//
//  1204.cpp
//  SWEA
//
//  Created by 김채은 on 2023/10/27.
//

#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    
    for(int i = 0; i < t; i++) {
        int n;
        cin >> n;
        
        int scores[101] = {0, };
        for(int j = 0; j < 1000; j++) {
            int score;
            cin >> score;
            scores[score]++;
        }
                
        int max = 0, idx = 0;
        
        for(int k = 0; k < 100; k++) {
            if(max <= scores[k]) {
                max = scores[k];
                idx = k;
            }
        }
        
        cout << "#" << i << " " << idx << endl;
    }
    
    return 0;
}
