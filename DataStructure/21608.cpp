//
//  21608.cpp
//  DataStructure
//
//  Created by 김채은 on 2024/02/17.
//

#include <iostream>
#include <vector>
using namespace std;

int map[21][21];  //자리 지도

int dx[] = {-1, 0, 0, 1};
int dy[] = {0, -1, 1, 0};

int main() {
    int n;
    cin >> n;
    
    vector<int> student;  //위치시켜야하는 학생 순서
    int like[402][4];  //좋아하는 학생
    for(int i = 0; i < n * n; i++) {
        int s;
        cin >> s;
        student.push_back(s);
        for(int j = 0; j < 4; j++) {
            cin >> like[s][j];
        }
    }
    
    for(int i = 0; i < n * n; i++) {
        int std = student[i];  //현재 위치시켜야하는 학생 번호
        
        int empty_map[n][n];
        int love_map[n][n];
        int max = -1;
        int res_x = 0;
        int res_y = 0;
        
        for(int j = 0; j < n; j++) {
            for(int k = 0; k < n; k++){
                int empty = 0;  //인접한 비어있는 칸 개수
                int love = 0;  //인접한 좋아하는 사람있는 수
                
                if(map[j][k] > 0) continue;  //이미 차지된 자리면 패스
                
                for(int d = 0; d < 4; d++) {  //빈자리
                    int nj = j + dx[d];
                    int nk = k + dy[d];
                    
                    if(nj < 0 || nk < 0 || nj >= n || nk >= n) continue;
                    if(map[nj][nk] == 0) empty++;  //인접한 빈자리
                    else {  //인접한 자리가 빈자리가 아니면 좋아하는 사람인지 확인
                        for(int f = 0; f < 4; f++) {
                            if(map[nj][nk] == like[std][f]) love++;
                        }
                    }
                }
                
                empty_map[j][k] = empty;
                love_map[j][k] = love;
                
                if(max < love) {
                    max = love;
                    res_x = j;
                    res_y = k;
                }
                else if(max == love) {  //좋아하는 사람 수가 같으면 빈곳이 많은 곳
                    if(empty_map[j][k] > empty_map[res_x][res_y]) {
                        res_x = j;
                        res_y = k;
                    }
                    else if(empty_map[j][k] == empty_map[res_x][res_y]) {
                        if(j < res_x) {
                            res_x = j;
                            res_y = k;
                        }
                        else if(j == res_x) {
                            if(k < res_y) {
                                res_x = j;
                                res_y = k;
                            }
                        }
                    }
                }
            }
        }
        map[res_x][res_y] = std;
    }
    
    int res = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            int std = map[i][j];
            
            int cnt = 0;
            for(int k = 0; k < 4; k++) {
                int nx = i + dx[k];
                int ny = j + dy[k];
                
                if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                
                for(int l = 0; l < 4; l++) {
                    if(like[std][l] == map[nx][ny]) cnt++;
                }
            }
            
            if(cnt == 1) res += 1;
            else if(cnt == 2) res += 10;
            else if(cnt == 3) res += 100;
            else if(cnt == 4) res += 1000;
        }
    }
    
    cout << res;
}
