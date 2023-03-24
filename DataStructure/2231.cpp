//
//  2231.cpp
//  DataStructure
//
//  Created by 김채은 on 2023/03/24.
//

#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;
    
    int sum = 0;
    int num;
    int cnt = 0;
    for(int i = 1; i < N; i++) {
        num = i;
        sum += num;
        while(num > 0) {
            sum += (num % 10);
            num = num / 10;
        }
        
        if(sum == N) {
            cout << i;
            cnt++;
            break;
        }
        sum = 0;
    }
    
    if(cnt == 0)
        cout << "0";
}
