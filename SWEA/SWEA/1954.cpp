//
//  1954.cpp
//  SWEA
//
//  Created by 김채은 on 2023/10/27.
//

#include <iostream>
#include <cstring>
using namespace std;

int n;
int arr[11][11];
int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};


int main() {
    int t;
    cin >> t;
    
    for(int c = 0; c < t; c++) {
        memset(arr,0,sizeof(arr));
        
        cin >> n;
        
        int i = 0, j = 0, dir = 0;
        arr[0][0] = 1;
        int cnt = 2;
        
        while(cnt <= n * n) {
            int rx = i + dx[dir];
            int ry = j + dy[dir];
            
            if(rx < 0 || rx >= n || ry < 0 || ry >= n || arr[rx][ry] > 0) {
                dir++;
                if(dir == 4) dir = 0;
                continue;
            }
            
            arr[rx][ry] = cnt++;
            i = rx;
            j = ry;
        }
        cout << "#" << c+1 << endl;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cout << arr[i][j] << " ";
            }
            cout << endl;
        }
    }
}
