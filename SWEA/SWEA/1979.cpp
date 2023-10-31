//
//  1979.cpp
//  SWEA
//
//  Created by 김채은 on 2023/10/31.
//

#include <iostream>
using namespace std;

int main() {
    int T, N, K;
    int map[16][16];
    int ans, cnt;
    
    cin >> T;
    
    for(int i = 0; i < T; i++) {
        cin >> N >> K;
        
        for(int a = 0; a < N; a++) {
            for(int b = 0; b < N; b++) {
                cin >> map[a][b];
            }
        }
        
        ans = 0;
        for(int a = 0; a < N; a++) {
            cnt = 0;
            for(int b = 0; b < N; b++) {
                if(map[a][b] == 1) {
                    cnt++;
                    
                    if(cnt > K) cnt = 0;
                    if(cnt == K && b == N-1) ans++;
                }
                else {
                    if(cnt == K) ans++;
                    cnt = 0;
                }
            }
        }
        
        for(int a = 0; a < N; a++) {
            cnt = 0;
            for(int b = 0; b < N; b++) {
                if(map[b][a] == 1) {
                    cnt++;
                    
                    if(cnt > K) cnt = 0;
                    if(cnt == K && b == N-1) ans++;
                }
                else {
                    if(cnt == K) ans++;
                    cnt = 0;
                }
            }
        }
        
        
        cout << "#" << i+1 << " " << ans << endl;
    }
}
