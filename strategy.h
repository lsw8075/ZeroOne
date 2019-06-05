
#ifndef STRATEGY_H
#define STRATEGY_H

class strategy {
public:
		
	virtual int decision(const int my[], const int oppo[], const int flip[], const int res[], const int n) = 0;
};

#endif
