

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#include "strategy.h"
class team9 : public strategy {
public:


int team8code[10] = {1, 0, 0, 1, 0, 1, 1, 1, 0, 0};
int team9code[10] = {0, 1, 1, 0, 1, 0, 0, 0, 1, 1};
int team2code[10] = {1, 0, 0, 1, 0, 1, 1, 1, 0, 0};
int team7code[10] = {0, 1, 1, 1, 0, 1, 1, 0, 1, 1};
bool team8flag = true, ourself = true, team2flag = true, team7flag = true;


virtual int decision(const int my[], const int oppo[], const int flip[], const int res[], const int n) {

    srand (time(NULL));
    int iSecret = rand() % 100 + 1;

    if(n == 0) {
        return 0;
    } else if(n == 1) {
        return 1;
    } else if(n == 2) {
        return 1;
    } else if(n == 3) {
        return 0;
    } else if(n == 4) {
        return 1;
    } else if(n == 5) {
        return 0;
    } else if(n == 6) {
        return 0;
    } else if(n == 7) {
        return 0;
    } else if(n == 8) {
        return 1;
    } else if(n == 9) {
        return 1;
    } else if(n == 10){
        for(int i = 0; i < 10; i++) {
            if(oppo[i] != team8code[i]) {
                team8flag = false;
                return 1;
            }
            if(oppo[i] != team9code[i]) {
                ourself = false;
                return 1;
            }
            if(oppo[i] != team2code[i]) {
                team2flag = false;
                return 1;
            }
            if(oppo[i] != team7code[i]) {
                team7flag = false;
                return 1;
            }
        }
    } else {
        if(team8flag || ourself || team2flag) {
            if(oppo[n - 1] == 1 && oppo[n - 2] == 1 && oppo[n - 3] == 1) {
                team8flag = false;
                ourself = false;
                team2flag = false;
                return 1;
            }
            if(iSecret <= 10) {
                return 1;
            } else {
                return 0;
            }
        } else {
            return 1;
        }
    }
}

};
