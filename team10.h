
#include <random>

#include "strategy.h"
class team10 : public strategy {
public:
	
int cyph[10] = {1, 0, 0, 1, 0, 1, 1, 1, 0, 0}, cyph2[10] = {0, 0, 0, 0, 0, 1, 1, 1, 1, 1}, me = 0, friends = 0;
int betray = 0;
bool myself = false;

virtual int decision(const int my[], const int oppo[], const int flip[], const int res[], const int n) {
	// friends Detection
	std::random_device rd;
	std::mt19937 g(rd());

	if(n == 0) {
		me = 0;
		betray = 0;
		friends = 0;
		myself = false;
	}
	if(n > 0 && n <= 10 && my[n-1] == oppo[n-1]) me++;
	if(n > 0 && n <= 10 && oppo[n-1] == cyph2[n-1]) friends++;

	if(n == 15) {
		int a[16];
		a[10] = 0; a[11] = 1; a[12] = 0; a[13] = 0; a[14] = 1;
		int b = 0;
		for(int i = 10; i < 15; i++) if(a[i] != oppo[i]) b++;
		if(b <= 1) myself = true;
	}

	if(n < 10) return cyph[n];	// 10회 이전에는 암호 체크
	else if(me > 8 && n < 15) {
		if(n == 11) return 1;
		if(n == 14) return 1;
		return 0;
	}
	else if((10 - me > 8) || (10 - friends > 8) || (n > 95 && oppo[57] + oppo[64] + oppo[95] <= 1)) {
		// friends: 97% 확률로 0, 2개 연속되지 않게 3% 확률로 1, 20회 이상 배신하면 1.
		// 01001 서로 다른게 1개?
		if(n-1 >= 10) betray += oppo[n-1];
		if(n-2 >= 10 && oppo[n-1] == oppo[n-2] && oppo[n-1] == 1) betray = 100;
		if(betray > 14) return 1;
		std::uniform_int_distribution<int> dist(1, 100);
		int k = dist(g) % 100;
		if(n >= 500 & k >= 98 && my[n-1] != 1) return 1;	// betray (2%)
		else return 0;
	}
	else if(me > 8 && myself) {	// Me: 랜덤으로 내다가 달라지는 순간 내던 것 계속 냄
		if(my[n - 1] != oppo[n - 1]) return my[n - 1];
		else {
			std::uniform_int_distribution<int> dist(0, 1);
			return dist(g);
		}
	}
	else {
		if(n == 57) return 0;
		if(n == 64) return 0;
		if(n == 95) return 0;

		return 1;	// General: 1
	}
	return 1;
}

};
