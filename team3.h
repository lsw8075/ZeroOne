

#include "strategy.h"
class team3 : public strategy {
public:


virtual int decision(const int my[], const int oppo[], const int flip[], const int res[], const int n)
{

    int count = 0;
    int tricked = 0;

    if(tricked){
        return 1;
    }

    switch(n){

        case 0:
        case 1:
        case 2:
        case 3:
        case 4:
            return 0;

        case 5:
        case 6:
        case 7:
        case 8:
        case 9:
            return 1;

        case 24:
            return 1;
        case 25:
            return 1;
        case 26:
            return 0;
        case 27:
            return 1;
        case 28:
            return 0;
        case 29:
            return 0;
    }


    //random team
    if(n >= 10 &&(oppo[0] == 0 && oppo[1] == 0 && oppo[2] == 0 && oppo[3] == 0 && oppo[4] == 0 && oppo[5] == 1 && oppo[6] == 1 && oppo[7] == 1 && oppo[8] == 1 & oppo[9] == 1)){
        if(oppo[n] == 1){
            count++;
            if(count/n >= 0.008){
                tricked = 1;
                return 1;
            }
        }
        return 0;
    }
    else if(n >= 30 && (oppo[24] == 0 && oppo[25] == 0 &&oppo[26] == 1 && oppo[27] == 0 && oppo[28] == 1 && oppo[29] == 1)){
        if(oppo[n] == 1){
            count++;
            if(count/n>= 0.008){
                tricked = 1;
                return 1;
            }
        }
        return 0;
    }

    else{
        return 1;
    }



    //1-10:
    // 1001011 100
    // 0110100 011





}

};
