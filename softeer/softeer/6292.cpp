//
//  6292.cpp
//  softeer
//
//  Created by 김채은 on 2024/03/25.
//

#include <iostream>
#include <cmath>
using namespace std;

long long k, p, n;  //처음 바이러스 개수, 증가율, 총 시간

long long cal(long long count) {
   if (count == 0) return 1;
   if (count == 1) return p % 1000000007;

   long long tmp = cal(count / 2) % 1000000007;
   if (count % 2 == 0) return tmp * tmp % 1000000007;
   else return tmp * tmp % 1000000007 * p % 1000000007;
}

int main() {
   cin >> k >> p >> n;

   long long ans = (k * cal(n * 10)) % 1000000007;

   cout << ans;
}
