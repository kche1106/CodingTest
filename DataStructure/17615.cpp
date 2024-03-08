//
//  17615.cpp
//  DataStructure
//
//  Created by 김채은 on 2024/03/08.
//

#include <iostream>
#include <vector>
using namespace std;

const int INF = 1e9 + 10;

int main() {
    int n;
    cin >> n;
    
    vector<char> ball;
    for(int i = 0; i < n; i++) {
        char c;
        cin >> c;
        ball.push_back(c);
    }
    
    int res = INF;
    int cnt = 0;
    bool other = false;
    //빨간색 왼쪽으로 모으기
    for(int i = 0; i < n; i++) {
        if(ball[i] == 'B') other = true;
        if(other && ball[i] == 'R') cnt++;
    }
    res = min(res, cnt);
    
    cnt = 0;
    other = false;
    for(int i = n-1; i >= 0; i--) {
        if(ball[i] == 'B') other = true;
        if(other && ball[i] == 'R') cnt++;
    }
    res = min(res, cnt);
    
    cnt = 0;
    other = false;
    for(int i = 0; i < n; i++) {
        if(ball[i] == 'R') other = true;
        if(other && ball[i] == 'B') cnt++;
    }
    res = min(res, cnt);
    
    cnt = 0;
    other = false;
    for(int i = n-1; i >= 0; i--) {
        if(ball[i] == 'R') other = true;
        if(other && ball[i] == 'B') cnt++;
    }
    res = min(res, cnt);
    
    cout << res;
}
