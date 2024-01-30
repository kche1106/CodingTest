#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <string>
#include <queue>
#include <stack>
#include <cmath>
#define INF 987654321

using namespace std;

int A, B, C;
vector<int> sum;

bool cmp(int x, int y) {
    if (x % 2 == 1 && y % 2 == 0) return false;
    else if (x % 2 == 1 && y % 2 == 1) {
        if (x < y) return true;
        else return false;
    }
    else if (x % 2 == 0 && y % 2 == 1) return true;
    else {
        if (x < y) return true;
        else return false;
    }
}

void solve() {
    sum.push_back(A);
    sum.push_back(B);
    sum.push_back(C);
    sum.push_back(A * B);
    sum.push_back(A * C);
    sum.push_back(B * C);
    sum.push_back(A * B * C);
    sort(sum.begin(), sum.end(), cmp);
    cout << sum[sum.size() - 1];
}

int main()
{
    cin.tie(0);
    cout.tie(0);
    cin >> A >> B >> C;
    solve();
    return 0;
}
출처: https://junseok.tistory.com/203 [알고리즘 모음(C++):티스토리]
