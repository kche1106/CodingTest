//
//  2002.cpp
//  DataStructure
//
//  Created by 김채은 on 2024/03/01.
//

#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    map<string, int> start;
    for(int i = 0; i < n; i++) {
        string car;
        cin >> car;
        start[car] = i;
    }
    
    vector<int> arrive;
    for(int i = 0; i < n; i++) {
        string car;
        cin >> car;
        arrive.push_back(start[car]);  //나간 순서에 들어온 순서 저장
    }
    
    int res = 0;
    for(int i = 0; i < n-1; i++) {
        for(int j = i+1; j < n; j++) {
            if(arrive[i] > arrive[j]) {
                res++;
                break;
            }
        }
    }
    
    cout << res;
}

/*
 4
 a b c d
 d a c b
 */
