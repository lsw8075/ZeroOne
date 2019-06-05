#include <stdlib.h>
#include <time.h>
#include "strategy.h"

class team7 : public strategy {
public:
	
	
// 채점자 주석 : static 변수를 쓰셨는데, class 안에 담느라 같은 의미의 (class-)전역으로 바꾸었습니다 
	
	int virus = 0;
	int randNum = 10;
	int count = 0;
	
virtual int decision(const int my[], const int oppo[], const int flip[], const int res[], const int n) {
	int temp = 0;
	int friend1_temp = 0;
	int friend2_temp = 0;
	int id[10] = { 0,1,1,1,0,1,1,0,1,1 };
	int friend_id1[10] = { 0,0,0,0,0,1,1,1,1,1 };
	int friend_id2[10] = { 0,1,1,0,1,0,0,0,1,1 };

	//static int virus = 0;
	//static int randNum = 10;
	int my_value = 0; // my[n-1] 을 저장
	//static int count = 0;
	srand(time(NULL));

	if (n < 10) {
		return id[n];
	}
	else {
		for (int i = 0; i < 10; i++) {
			if (oppo[i] == id[i]) {
				temp++;
			}
			else if (oppo[i] == friend_id1[i]) {
				friend1_temp++;
			}
			else if (oppo[i] == friend_id2[i]) {
				friend2_temp++;
			}
		}
		if (temp == 10) {
			return 0;
		}
		else if (friend1_temp == 0 || friend2_temp == 0) {
			if (virus == 1) {
				return 1;
			}
			else if (oppo[n - 2] == 1 && oppo[n - 1] == 1) {
				virus = 1;
				return 1;
			}
			else {
				return 0;
			}
		}
		else {
			if (rand() % randNum == 1) {
				if (oppo[n - 3] == 0 && my[n - 2] == 1 && oppo[n - 1] == 0) {
					if (randNum > 4) {
						randNum--;
					}
					else {
						randNum = 4;
					}
				}

				return 1;
			}
			else {
				return oppo[n - 1];
			}
		}
	}
}

};
