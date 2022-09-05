//
//  14888.cpp
//  DataStructure
//
//  Created by 김채은 on 2022/09/05.
//

#include <iostream>
using namespace std;

int N;
int num[11];
int op[4];
int minimum = 1000000001;
int maximum = -1000000001;

void func(int result, int idx)
{
    if(idx == N) {
        if(result > maximum)
            maximum = result;
        if(result < minimum)
            minimum = result;
        return;
    }
    
    for(int i = 0; i < 4; i++) {
        if(op[i] > 0) {
            op[i]--;
            
            if(i == 0)
                func(result + num[idx], idx+1);
            else if(i == 1)
                func(result - num[idx], idx+1);
            else if(i == 2)
                func(result * num[idx], idx+1);
            else
                func(result / num[idx], idx+1);
            
            op[i]++;
        }
    }
    return;
}

int main() {
    cin >> N;
    
    for(int i = 0; i < N; i++)
        cin >> num[i];
     
    for(int i = 0; i < 4; i++)
        cin >> op[i];
    
    func(num[0],1);
    
    cout << maximum << '\n' << minimum;
}

