//
//  1744.cpp
//  DataStructure
//
//  Created by 김채은 on 2024/02/25.
//

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> pos;
    vector<int> neg;
    int one = 0;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if(x == 1) one++;
        else if(x > 1) pos.push_back(x);
        else if(x <= 0) neg.push_back(x);
    }
    
    sort(pos.begin(), pos.end(), greater<int>());
    sort(neg.begin(), neg.end());
    
    int sum = 0;
    for(int i = 0; i < pos.size(); i+=2) {
        if(i+1 < pos.size()) sum += pos[i] * pos[i+1];
    }
    if(pos.size() % 2 == 1) sum += pos.back();  //홀수 개일때 남은 거 하나 더해줌
    
    for(int i = 0; i < neg.size(); i+=2) {
        if(i+1 < neg.size()) sum += neg[i] * neg[i+1];
    }
    if(neg.size() % 2 == 1) sum += neg.back();
    
    sum += one;
    
    cout << sum;
}
