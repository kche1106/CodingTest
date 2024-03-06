//
//  20006.cpp
//  DataStructure
//
//  Created by 김채은 on 2024/03/05.
//

#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
using namespace std;

struct Player{
    int level;
    string nickname;
    
    Player(int l, string n) {
        level = l; nickname = n;
    }
};

struct Room {
    int level;
    vector<Player> player;
    
    Room(int l, Player p) {
        level = l;
        player.push_back(p);
    }
};

bool cmp(Player p1, Player p2) {
    return p1.nickname < p2.nickname;
}

int main() {
   int p, m;  //플레이어 수, 방 정원
   cin >> p >> m;

   vector<Player> player;
   for (int i = 0; i < p; i++) {
      int l; string n;
      cin >> l >> n;
      player.push_back(Player(l, n));
   }

    vector<Room> room;  //생성순서, 레벨, 플레이어
    room.push_back(Room(player[0].level, player[0]));
   for (int i = 1; i < player.size(); i++) {
       
       bool tmp = false;
       int idx = 0;
       for (int j = 0; j < room.size(); j++) {
           if (room[j].player.size() < m && room[j].level - 10 <= player[i].level && room[j].level + 10 >= player[i].level) {
               tmp = true;
               idx = j;
               break;
           }
      }
       if (tmp) {
           room[idx].player.push_back(player[i]);
       }
       else {
           room.push_back(Room(player[i].level, player[i]));
       }
   }
    
    for(int i = 0; i < room.size(); i++) {
        sort(room[i].player.begin(), room[i].player.end(), cmp);
    }
    
    for(auto i = 0; i < room.size(); i++) {
        if(room[i].player.size() == m) {
            cout << "Started!\n";
            for(int j = 0; j < room[i].player.size(); j++) {
                cout << room[i].player[j].level << " " << room[i].player[j].nickname << "\n";
            }
        }
        else {
            cout << "Waiting!\n";
            for(int j = 0; j < room[i].player.size(); j++) {
                cout << room[i].player[j].level << " " << room[i].player[j].nickname << "\n";
            }
        }
    }
}
