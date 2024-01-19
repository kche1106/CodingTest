//
//  20055.cpp
//  DataStructure
//
//  Created by 김채은 on 2024/01/18.
//

#include <iostream>
#include <deque>
using namespace std;

int n, k;
deque<int> a;
deque<int> robot;

void rotate() {
    a.push_front(a.back());
    a.pop_back();
    
    robot.push_front(robot.back());
    robot.pop_back();
    robot[n-1] = 0;  //벨트가 회전한 후 n번 칸에 있는 로봇 내리기
}

void move() {
    for(int i = n-2; i >= 0; i--) {
        if(robot[i] == 1 && robot[i+1] == 0 && a[i+1] > 0) {
            robot[i] = 0;
            robot[i+1] = 1;
            a[i+1]--;
        }
    }
    
    robot[n-1] = 0;
}

void put() {
    if(robot[0] == 0 && a[0] > 0) {
        robot[0] = 1;
        a[0]--;
    }
}

int check() {
    int cnt = 0;
    for(int i = 0; i < a.size(); i++) {
        if(a[i] == 0) cnt++;
    }
    return cnt;
}

int main() {
    cin >> n >> k;
    
    for(int i = 0; i < 2*n; i++) {
        int num;
        cin >> num;
        a.push_back(num);
        robot.push_back(0);
    }
    
    int sum = 0;
    while (true) {
        sum++;
        rotate();
        move();
        put();
        
        int c = check();
        if(c >= k) break;
    }
    
    cout << sum << endl;
}
