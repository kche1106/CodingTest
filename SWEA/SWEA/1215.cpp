//
//  1215.cpp
//  SWEA
//
//  Created by 김채은 on 2023/11/06.
//

#include <iostream>
using namespace std;

int map[9][9];
int n, res;

void wid(int x, int y) {
    vector<int> v;
    bool flag = true;
    
    for(int i = 0; i < n; i++) {
        v.push_back(map[x][y+i]);
    }
    
    
    for(int i = 0, j = n-1; i < n/2; i++, j--) {
        if(v[i] != v[j]) flag = false;
    }
    
    if(flag) {
        res++;
    }
}

void hei(int x, int y) {
    vector<int> v;
    bool flag = true;
    
    for(int i = 0; i < n; i++) {
        v.push_back(map[x+i][y]);
    }
    
    for(int i = 0, j = n-1; i < n/2; i++, j--) {
        if(v[i] != v[j]) flag = false;
    }
    
    if(flag) {
        res++;
    }
}

int main() {
    
    for(int i = 1; i <= 10; i++) {
        res = 0;
        cin >> n;
        
        for(int j = 0; j < 8; j++) {
            string s;
            cin >> s;
            for(int k = 0; k < 8; k++) {
                map[j][k] = s[k];
            }
        }
        
        for(int j = 0; j < 8; j++) {
            for(int k = 0; k <= 8 - n; k++) {
                wid(j, k);
            }
        }
        
        for(int j = 0; j <= 8 - n; j++) {
            for(int k = 0; k < 8; k++) {
                hei(j, k);
            }
        }
        
        cout << "#" << i << " " << res << endl;
    }
}
