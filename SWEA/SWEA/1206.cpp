//
//  1206.cpp
//  SWEA
//
//  Created by 김채은 on 2023/11/01.
//

#include <iostream>
using namespace std;

int main() {
    
    for(int i = 1; i <= 10; i++) {
        int n, h[1000], res = 0;
        cin >> n;
        
        for(int x = 0; x < n; x++) cin >> h[x];
        
        for(int x = 2; x < n - 2; x++) {
            int floor = h[x];
            for(int y = floor; y >= 1; y--) {
                if(h[x-1] < y && h[x-2] < y && h[x+1] < y && h[x+2] < y) res++;
                else break;
            }
        }
        cout << "#" << i << " " << res << endl;
    }
}

/*
int main() {
    
    for(int i = 1; i <= 10; i++) {
        int n, h[1000], res = 0;
        cin >> n;
        
        for(int x = 0; x < n; x++) cin >> h[x];
        
        for(int x = 2; x < n - 2; x++) {
            int max_num = max(max(h[x-2], h[x-1]), max(h[x+1], h[x+2]));
            if(max_num < h[x]) res += (h[x] - max_num);
        }
        
        cout << "#" << i << " " << res << endl;
    }
}
*/
