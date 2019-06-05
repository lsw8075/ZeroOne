#include <stdlib.h>

#include "strategy.h"
class team4 : public strategy {
public:

int repeat=0;
int cooperate=0;
int detect=15;
int myself=0;
virtual int decision(const int my[], const int oppo[], const int flip[], const int res[], const int n)
{
	int identify_id[10]={0,0,0,0,0,1,1,1,1,1};

	//detect part
	if(n==0)
	{
		repeat=0;
		cooperate=0;
		detect=15;
		myself=0;
	}

	if(n<10)
	{
		return identify_id[n];

	}
	else if(n==10)
	{
		int result=0;
		for(int i=0;i<10;i++)
			result+=(identify_id[i]==oppo[i]);

		if(result>=9)
		{
			myself=1;

			srand(n);
			return rand()%2;
		}
	}

	if(myself==1)
	{
		if(oppo[n-1]^my[n-1])
			return my[n-1];
		else return rand()%2;
	}
	else
	{
		if(oppo[n]==1)
		{
			detect--;
			repeat++;
		}
		else
			repeat=0;

		if (detect <=0 || repeat==3)
		{
			cooperate=1;
		}

			return cooperate;

	}

}
};
