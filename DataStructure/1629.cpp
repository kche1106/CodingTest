//
//  1629.cpp
//  DataStructure
//
//  Created by 김채은 on 2024/02/11.
//

#include <iostream>
using namespace std;

long long a, b, c;

long long pow(long long a, long long b, long long c) {
    if(b == 0) return 1;
    if(b == 1) return a % c;
    
    long long temp = pow(a, b/2, c);
    if(b % 2 == 0) return (temp * temp) % c;
    else return ((temp * temp) % c) * a % c;
}

int main() {
    cin >> a >> b >> c;
    
    cout << pow(a, b, c);
}
