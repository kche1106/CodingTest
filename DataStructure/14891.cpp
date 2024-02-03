//
//  14891.cpp
//  DataStructure
//
//  Created by 김채은 on 2024/02/03.
//

#include <iostream>
#include <deque>
#include <cstring>
using namespace std;

int rot[5];
int check[5];
deque<int> d[5];

void setdir(int num, int dir) {
    rot[num] = dir;
    check[num] = 1;
    
    if(num - 1 > 0 && check[num-1] == 0) {
        if(dir == 0) setdir(num-1, 0);
        else if(d[num][6] != d[num-1][2]) setdir(num-1, -dir);
        else setdir(num-1, 0);
    }
    if(num + 1  <= 4 && check[num+1] == 0) {
        if(dir == 0) setdir(num+1, 0);
        else if(d[num][2] != d[num+1][6]) setdir(num+1, -dir);
        else setdir(num+1, 0);
    }
}

void rotate() {
    
    for(int i = 1; i <= 4; i++) {
        if(rot[i] == 0) continue;
        else if(rot[i] == 1) {
            d[i].push_front(d[i].back());
            d[i].pop_back();
        }
        else if(rot[i] == -1) {
            d[i].push_back(d[i].front());
            d[i].pop_front();
        }
    }
}

int main() {
    for(int i = 1; i <= 4; i++) {
        string s;
        cin >> s;
        
        for(int j = 0; j < s.length(); j++)
            d[i].push_back(s[j] - '0');
    }
    
    int k;
    cin >> k;
    for(int i = 0; i < k; i++) {
        int num, dir;
        cin >> num >> dir;
        
        memset(check, 0, sizeof(check));
        
        setdir(num, dir);
        rotate();
    }
    
    int score = 0;
    if(d[1][0] == 1) score += 1;
    if(d[2][0] == 1) score += 2;
    if(d[3][0] == 1) score += 4;
    if(d[4][0] == 1) score += 8;
    
    cout << score << endl;
}
