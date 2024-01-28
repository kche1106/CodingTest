//
//  1934.cpp
//  DataStructure
//
//  Created by 김채은 on 2024/01/29.
//

#include<iostream>
 
using namespace std;
 
int divide(int x, int y)
{
    if (x % y == 0)
        return y;
    else
        return divide(y, x % y);
}
 
int main()
{
    int T;
    int A, B;
    cin >> T;
 
    for (int i = 0; i < T; i++)
    {
        cin >> A >> B;
        if (A >= B)
        {
            cout << A * B / divide(A, B) << "\n";
        }
        else
            cout << A * B / divide(B, A) << "\n";
    }
}

