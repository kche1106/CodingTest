//
//  2798.cpp
//  DataStructure
//
//  Created by 김채은 on 2022/09/24.
//

#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<int> v;
int result;

void func(int idx, int count, int sum) {

    if(count == 3 && sum <= M) {
        result = max(result, sum);
        return;
    }
    
    if(idx >= N || count > 3 || sum > M)
        return;

    func(idx+1, count + 1, sum + v.at(idx));
    func(idx+1, count, sum);
}

int main() {

    cin >> N >> M;
    
    for(int i = 0; i < N; i++) {
        int k;
        cin >> k;
        v.push_back(k);
    }

    
    func(0, 0, 0);

    cout << result;
}
