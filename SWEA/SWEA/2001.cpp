//
//  2001.cpp
//  SWEA
//
//  Created by 김채은 on 2023/10/27.
//

#include <iostream>
using namespace std;

int n, m;
int arr[16][16];
int isVisit[16][16];
int sum = 0, cnt = 0;

int main() {
    int t;
    cin >> t;
    
    for(int i = 0; i < t; i++) {
        cin >> n >> m;
        
        for(int j = 0; j < n; j++) {
            for(int k = 0; k < n; k++) {
                cin >> arr[j][k];
            }
        }
        
        int max = 0;
        int sum[16][16] = {0,};
        for(int x = 0; x < n; x++) {
            for(int y = 0; y < n; y++) {
                
                for(int q = 0; q < m; q++) {
                    for(int p = 0; p < m; p++) {
                        sum[x][y] += arr[x + q][y + p];
                    }
                }
            }
        }
        
        for(int x = 0; x < n; x++) {
            for(int y = 0; y < n; y++) {
                if(max < sum[x][y]) max = sum[x][y];
            }
        }
        
        cout << "#" << i+1 << " " << max << endl;
    }
}
