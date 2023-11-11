//
//  1208.cpp
//  SWEA
//
//  Created by 김채은 on 2023/11/01.
//

#include <iostream>
using namespace std;

int main() {
    for(int i = 1; i <= 10; i++) {
        int dump, h[100], res = 0;
        cin >> dump;
        
        for(int i = 0; i < 100; i++) cin >> h[i];
        
        while(true){
            int max = 0, min = 101, maxi = 0, mini = 0;
            for(int j = 0; j < 100; j++) {
                if(max < h[j]) {
                    max = h[j];
                    maxi = j;
                }
                if(min > h[j]) {
                    min = h[j];
                    mini = j;
                }
            }
            if(dump == 0) {
                res = max - min;
                break;
            }
            
            h[maxi]--; h[mini]++;
            dump--;
        }
        
        cout << "#" << i << " " << res << endl;
    }
}
