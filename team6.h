
#include "strategy.h"
class team6 : public strategy {
public:



virtual int decision(const int my[], const int oppo[], const int flip[], const int res[], const int n)
{
	//��ȣ�Դϴ�. Ư�� ������ �츮�� �Ʊ����� �˷��ݴϴ�.
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

	//������ġ�Դϴ�. �� �� 1�� �Ǵ� ���縦 �����մϴ�.
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

	//���� ���� �ٽ� �˰����Դϴ�. ����� �Ǵܰ� ���� �Ǵ��� ���� ���� �������� �Ǵ��մϴ�.

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
