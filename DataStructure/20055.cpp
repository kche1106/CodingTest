//
//  20055.cpp
//  DataStructure
//
//  Created by 김채은 on 2024/01/18.
//

#include <deque>
#include <iostream>
#include <vector>

using namespace std;

deque<int> a;
deque<int> robot;

int N, K, step;

void rotate(){
    a.push_front(a.back());
    a.pop_back();
    
    robot.push_front(robot.back());
    robot.pop_back();
    robot[N - 1] = 0;
}

void move()
{
    for (int i = N - 2; i >= 0; i--) {
        if (robot[i + 1] == 0 && a[i + 1] > 0 && robot[i] == 1) {
            robot[i] = 0;
            robot[i + 1] = 1;
            a[i + 1]--;
        }
    }
    robot[N - 1] = 0;
}

void put_robot()
{
    if (!robot[0] && a[0] > 0) {
        robot[0] = 1;
        a[0]--;
    }
}

int check()
{
    int count_ = 0;
    for (int i = 0; i < 2 * N; i++) {
        if (a[i] == 0)
            count_++;
    }
    return count_;
}

int main()
{
    step = 1;

    cin >> N >> K;
    for (int i = 0; i < 2 * N; i++) {
        int in;
        cin >> in;
        a.push_back(in);
        robot.push_back(0);
    }

    while (true) {
        rotate();
        move();
        put_robot();

        int c = check();
        if (c >= K) {
            cout << step << "\n";
            return 0;
        }
        step++;
    }

    return 0;
}
