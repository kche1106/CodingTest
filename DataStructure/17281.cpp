//
//  17281.cpp
//  DataStructure
//
//  Created by 김채은 on 2024/03/03.
//

#include <iostream>
#include <cstring>
using namespace std;

int n;
int record[51][10];
int order[10];  //타순
int visited[10];
int ans;

void play() {
    int base[4];
    int score = 0;
    int start_player = 1;
    
    for(int i = 1; i <= n; i++) {  //이닝 반복
        int out = 0;
        bool nextIning = false;
        memset(base, 0, sizeof(base));
        
        while(true) {  //3아웃이 안될경우 같은 이닝 반복
            for(int j = start_player; j <= 9; j++) {
                int player = record[i][order[j]];
                
                /* 아웃 */
                if(player == 0) out++;
                /* 1루타 */
                else if(player == 1) {
                    for(int b = 3; b >= 1; b--) {
                        if(base[b] == 1) {
                            if(b == 3) {
                                base[b] = 0;
                                score++;
                            }
                            else {
                                base[b] = 0;
                                base[b+1] = 1;
                            }
                        }
                    }
                    base[1] = 1;
                }
                /* 2루타 */
                else if(player == 2) {
                    for(int b = 3; b >= 1; b--) {
                        if(base[b] == 1) {
                            if(b == 3 || b == 2) {
                                base[b] = 0;
                                score++;
                            }
                            else {
                                base[b] = 0;
                                base[b+2] = 1;
                            }
                        }
                    }
                    base[2] = 1;
                }
                /* 3루타 */
                else if(player == 3) {
                    for(int b = 3; b >= 1; b--) {
                        if(base[b] == 1) {
                            if(b == 3 || b == 2 || b == 1) {
                                base[b] = 0;
                                score++;
                            }
                            else {
                                base[b] = 0;
                                base[b+3] = 1;
                            }
                        }
                    }
                    base[3] = 1;
                }
                /* 홈런 */
                else {
                    for(int b = 3; b >= 1; b--) {
                        if(base[b] == 1) {
                            base[b] = 0;
                            score++;
                        }
                    }
                    score++;
                }
                
                if(out == 3) {
                    start_player = j+1;
                    if(start_player == 10) start_player = 1;  //한바퀴 돌았음
                    nextIning = true;
                    break;
                }
            }
            if(nextIning) break;
            start_player = 1;  //3아웃이 안되었으면 첫 타순부터
        }
    }
    if(score > ans) ans = score;
}

void mkorder(int cnt) {  //cnt는 타순 몇번인지
    if(cnt == 10) {
        play();
        return;
    }
    
    for(int i = 1; i <= 9; i++) {  //타자
        if(!visited[i]) {
            visited[i] = 1;
            order[i] = cnt;  //i번 타자는 cnt 타순
            mkorder(cnt+1);
            visited[i] = 0;
        }
    }
}

int main() {
    cin >> n;  //이닝 수
    
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= 9; j++) {
            cin >> record[i][j];  //i는 이닝 j는 선수 번호
        }
    }
    
    visited[4] = 1;  //4번타자는 순서 정해짐
    order[4] = 1;  //4번 타자는 1번 순서
    mkorder(2);
    
    cout << ans << endl;
    
}
