//
//  20044.cpp
//  DataStructure
//
//  Created by 김채은 on 2024/02/04.
//

#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;  //팀의 수
    cin >> n;

    vector<int> v;
    for(int i = 0; i < 2 * n; i++) {
        int a;
        cin >> a;
        v.push_back(a);
    }
    
    sort(v.begin(), v.end());
    
    int min = 200000;
    for(int i = 0; i < n; i++) {
        int sum = v[i] + v[2*n-i-1];
        if(sum < min) min = sum;
    }
    
    cout << min;
}
