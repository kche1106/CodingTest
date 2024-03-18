//
//  22251.cpp
//  DataStructure
//
//  Created by 김채은 on 2024/03/18.
//

#include <iostream>
#include <vector>
using namespace std;

int n, k, p, x;  //n층까지, k자리수, p개 반전, x층에 멈춤
int res;
vector<int> v[10];

void func() {
    for(int i = 1; i <= n; i++) {
        if(i == x) continue;
        
        int cnt = 0;
        int from = x, to = i;
        for(int j = 0; j < k; j++) {
            cnt += v[from % 10][to % 10];
            from /= 10;
            to /= 10;
        }
        if(cnt <= p) res++;
    }
}

int main() {
    cin >> n >> k >> p >> x;
    
    int num[10][7] = {
        {1, 1, 1, 0, 1, 1, 1},
        {0, 0, 1, 0, 0, 1, 0},
        {1, 0, 1, 1, 1, 0, 1},
        {1, 0, 1, 1, 0, 1, 1},
        {0, 1, 1, 1, 0, 1, 0},
        {1, 1, 0, 1, 0, 1, 1},
        {1, 1, 0, 1, 1, 1, 1},
        {1, 0, 1, 0, 0, 1, 0},
        {1, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 0, 1, 1}
    };
    
    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++) {
            int cnt = 0;
            for(int k = 0; k < 7; k++) {
                if(num[i][k] != num[j][k]) cnt++;
            }
            v[i].push_back(cnt);
        }
    }
    
    func();
    cout << res;
}
