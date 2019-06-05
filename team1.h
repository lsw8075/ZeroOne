

#include "strategy.h"
class team1 : public strategy {
public:
	
/// 우리의 전략은 랜덤입니다~!~
virtual int decision(const int my[], const int oppo[], const int flip[], const int res[], const int n) {
    int id[10] = { 0, 1, 1, 0, 1, 0, 0, 0, 1, 1 };
    if (n < 10) return id[n];

    int chanju_idx[8] = { 13, 17, 19, 23, 29, 31, 37, 41 };
    int chanju_num[8] = { 1, 0, 1, 0, 1, 0, 1, 0};
    for(int i=0;i<8;i++) {
        if(chanju_idx[i] == n) {
            return chanju_num[i];
        }
    }

    int is_me = 0;
    for(int i=0; i < 10; i++)
        if (id[i] == oppo[i]) is_me++;

    int my_idx[5] = { 32, 33, 34, 35, 36 };
    int my_num[5] = { 0, 1, 0, 0, 1};
    for(int i=0;i<5;i++) {
        if(my_idx[i] == n) {
            return my_num[i];
        } else if (oppo[my_idx[i]] == my_num[i]) {
            is_me++;
        }
    }

    if (is_me >= 13) {
        for(int i=38; i<n; i++) {
            if (my[i] < oppo[i]) return 1;
            else if (my[i] > oppo[i]) return 0;
        }

        return 2;
    } else {
        int is_chanju = 0;
        for(int i=0;i<8;i++) {
            if(chanju_idx[i] >= n) break;
            if(oppo[chanju_idx[i]] != chanju_num[i])
               is_chanju++;
        }

        if (is_chanju >= 7) {
            return oppo[n-1] && oppo[n-2];
        } else {
            return 1;
        }
    }
}
};
