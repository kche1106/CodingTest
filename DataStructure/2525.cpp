//
//  2525.cpp
//  DataStructure
//
//  Created by 김채은 on 2024/02/02.
//

#include <iostream>
 
using namespace std;
 
int main(int argc, char const *argv[]) {
    int A, B, C;
    cin >> A >> B >> C;
 
    int min = 60 * A + B;   // 시 -> 분
    min += C;
 
    int hour = (min / 60) % 24;
    int minute = min % 60;
 
    cout << hour << " " << minute;
    return 0;
}
