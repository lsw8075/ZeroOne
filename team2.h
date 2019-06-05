
#include "strategy.h"
class team2 : public strategy {
public:


bool passCheck(const int pass[], const int oppo[])
{
    int wrong = 0;
    for (int i = 0; i < 10; i++)
    {
        if (pass[i] != oppo[i]) wrong++;
        if (wrong > 1) return false;
    }
    return true;
}
bool me(const int mypass[], const int oppo[])
{
    return passCheck(mypass, oppo);
}
bool meele(const int oppo[])
{
    int meelePass[1][10] = { {0,1,1,0,1,0,0,0,1,1} };
    for (int i = 0; i < 1; i++)
    {
        if (passCheck(oppo,meelePass[i])) return true;
    }
    return false;
}


virtual int decision(const int my[], const int oppo[], const int flip[], const int res[], const int n)
{
    int mypass[10] = {1,0,0,1,0,1,1,1,0,0};
    if (n < 20) return mypass[n];
    if (me(mypass, oppo))
    {
        if (my[n - 1] != oppo[n - 1]) return my[n - 1];
        if (my[n - 2] != oppo[n - 2]) return my[n - 2];
        if (my[n - 3] != oppo[n - 3]) return my[n - 3];

        else return 2;
    }
    if (meele(oppo))
    {
        if(oppo[n-3]+oppo[n-2]+oppo[n-1]>1) return 1;
        return 0;
    }
    return 1;
}

};
