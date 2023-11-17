//
//  1860.cpp
//  SWEA
//
//  Created by 김채은 on 2023/11/17.
//

#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin >> t;
    
    for(int i = 0; i < t; i++) {
        int n, m, k;
        cin >> n >> m >> k;
        
//        int fish[100] = {0, };
//        for(int j = 1; j < 100; j++) {
//            if(j % m == 0) fish[j] = fish[j-1] + k;
//            else fish[j] = fish[j-1];
//        }
        
        int people[n];
        for(int j = 0; j < n; j++) {
            cin >> people[j];
        }
        sort(people, people+n);
        
        bool flag = true;
        for(int j = 0; j < n; j++) {
//            int person = people[j];
//            if(fish[person] <= 0) {
//                flag = false;
//                break;
//            }
//            else {
//                for(int k = person; k < 100; k++) {
//                    fish[k] -= 1;
//                }
//            }
            if(people[j]/m * k < j+1) {  //붕어빵 수가 손님 수보다 적다면
                flag = false;
                break;
            }
        }
        
        if(flag) cout << "#" << i+1 << " Possible" << endl;
        else cout << "#" << i+1 << " Impossible" << endl;
    }
}
