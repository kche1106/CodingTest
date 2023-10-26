//
//  2748.cpp
//  DataStructure
//
//  Created by 김채은 on 2023/10/26.
//

#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    long long fib[91];
    
    fib[0] = 0; fib[1] = 1;
    for(int i = 2; i <= n; i++) {
        fib[i] = fib[i-1] + fib[i-2];
    }
    
    cout << fib[n] << endl;
}
