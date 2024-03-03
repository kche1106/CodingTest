//
//  2290.cpp
//  DataStructure
//
//  Created by 김채은 on 2024/03/03.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int s;
    long long n;
    cin >> s >> n;
    
    int number[10][7] = {
        {1, 1, 1, 0, 1, 1, 1},  //0
        {0, 0, 1, 0, 0, 1, 0},  //1
        {1, 0, 1, 1, 1, 0, 1},  //2
        {1, 0, 1, 1, 0, 1, 1},  //3
        {0, 1, 1, 1, 0, 1, 0},  //4
        {1, 1, 0, 1, 0, 1, 1},  //5
        {1, 1, 0, 1, 1, 1, 1},  //6
        {1, 0, 1, 0, 0, 1, 0},  //7
        {1, 1, 1, 1, 1, 1, 1},  //8
        {1, 1, 1, 1, 0, 1, 1}   //9
    };
    
    vector<int> v;
    while(n > 0) {
        v.push_back(n % 10);
        n /= 10;
    }
    reverse(v.begin(), v.end());
    
    //0 (맨 윗줄)
    for(int i = 0; i < v.size(); i++) {
        int num = v[i];
        if(number[num][0]) {
            cout << " ";
            for(int j = 0; j < s; j++) cout << "-";
            cout << " ";
        }
        else {
            for(int j = 0; j < s+2; j++) cout << " ";
        }
        cout << " ";
    }
    cout << endl;
    
    //1,2
    for(int k = 0; k < (2*s+3)/2-1; k++) {
        for(int i = 0; i < v.size(); i++) {
            int num = v[i];
            if(number[num][1] && number[num][2]) {
                cout << "|";
                for(int j = 0; j < s; j++) cout << " ";
                cout << "|";
            }
            else if(number[num][1] == 0 && number[num][2]) {
                cout << " ";
                for(int j = 0; j < s; j++) cout << " ";
                cout << "|";
            }
            else if(number[num][1] && number[num][2] == 0) {
                cout << "|";
                for(int j = 0; j < s; j++) cout << " ";
                cout << " ";
            }
            else if(number[num][1] == 0 && number[num][2] == 0) {
                for(int j = 0; j < s+2; j++) cout << " ";
            }
            cout << " ";
        }
        cout << endl;
    }
    
    //3
    for(int i = 0; i < v.size(); i++) {
        int num = v[i];
        if(number[num][3]) {
            cout << " ";
            for(int j = 0; j < s; j++) cout << "-";
            cout << " ";
        }
        else {
            for(int j = 0; j < s+2; j++) cout << " ";
        }
        cout << " ";
    }
    cout << endl;
    
    //4 5
    for(int k = 0; k < (2*s+3)/2-1; k++) {
        for(int i = 0; i < v.size(); i++) {
            int num = v[i];
            if(number[num][4] && number[num][5]) {
                cout << "|";
                for(int j = 0; j < s; j++) cout << " ";
                cout << "|";
            }
            else if(number[num][4] == 0 && number[num][5]) {
                cout << " ";
                for(int j = 0; j < s; j++) cout << " ";
                cout << "|";
            }
            else if(number[num][4] && number[num][5] == 0) {
                cout << "|";
                for(int j = 0; j < s; j++) cout << " ";
                cout << " ";
            }
            else if(number[num][4] == 0 && number[num][5] == 0) {
                for(int j = 0; j < s+2; j++) cout << " ";
            }
            cout << " ";
        }
        cout << endl;
    }
    
    //6
    for(int i = 0; i < v.size(); i++) {
        int num = v[i];
        if(number[num][6]) {
            cout << " ";
            for(int j = 0; j < s; j++) cout << "-";
            cout << " ";
        }
        else {
            for(int j = 0; j < s+2; j++) cout << " ";
        }
        cout << " ";
    }
    cout << endl;
}
