
#include "strategy.h"
class team6 : public strategy {
public:



virtual int decision(const int my[], const int oppo[], const int flip[], const int res[], const int n)
{
	//암호입니다. 특정 조에게 우리는 아군임을 알려줍니다.
	if (n==0)
		return 0;
	if (n==1)
		return 0;
	if (n==2)
		return 0;
	if (n==3)
		return 0;
	if (n==4)
		return 0;
	if (n==5)
		return 1;
	if (n==6)
		return 1;
	if (n==7)
		return 1;
	if (n==8)
		return 1;
	if (n==9)
		return 1;

	//안전장치입니다. 둘 다 1이 되는 참사를 방지합니다.
	if (n==100)
		return 0;
	if (n==200)
		return 0;
	if (n==300)
		return 0;
	if (n==400)
		return 0;
	if (n==500)
		return 0;
	if (n==600)
		return 0;
	if (n==700)
		return 0;
	if (n==800)
		return 0;
	if (n==900)
		return 0;

	//저희 조의 핵심 알고리즘입니다. 상대의 판단과 나의 판단이 같은 지를 기준으로 판단합니다.

	if (n > 9)
	{
		if(my[n-1]==0)
		{
			if(my[n-1]==oppo[n-1])
				return 0;
			else
				return 1;
		}
		else
		{
			if(my[n-1]==oppo[n-1])
				return 1;
			else
				return 0;
		}
	}
}

};
