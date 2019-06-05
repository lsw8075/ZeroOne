


#include "strategy.h"
class team5 : public strategy {
public:

virtual int decision(const int my[], const int oppo[], const int flip[], const int res[], const int n) {

   int count = 0;
   int VIP_3=0, VIP_10=0;
   bool ME = true;

   // from 0 to 3 _ check if it's myself
   if (n > 3){
      ME = true;
      for( int i=0; i<5; i++){
         if(my[i]!=oppo[i]) ME=false;
      }
   }

   // initialize VIP_3
   if (n > 29 && !VIP_10){
      for (int i = 24; i <= 29; i++){
         if (! my[i]^oppo[i]){
            count++;
         }
      }
      if (count >= 2){
         VIP_3 = 0;
      }
      else {
         VIP_3 = 1;
      }
   }

   // initialize VIP_10
   if(n>95 && !VIP_3){
      if(oppo[57]==0 && oppo[64]==0 && oppo[95]==0) VIP_10 = 1;
   }

   if((n < 96) && !VIP_10 && !VIP_3 && !ME){
      switch (n){
   
      // 우리 조 식별 코드
      case 0: return 0;
      case 1: return 1;
      case 2: return 1;
      case 3: return 0;
      case 4: return 1;
      case 5:   return 0;
      case 6: return 0;

      // VIP_10 을 위한 0 선택
      case 57: return 0;
      case 64: return 0;
      case 95: return 0;

      // VIP_3 을 위한 0,1 선택
      case 24: return   0;
      case 25: return   0;
      case 26: return   1;
      case 27: return   0;
      case 28: return   1;
      case 29: return   1;

      default : return 1;
      }
   }

   // If it is me
   if(ME){
      if(flip[n-1])return my[n-2];
      if(flip[n-1]&&flip[n-2]) return my[n-3];
      
      if (res[n-1] != 0 && res[n-1] != 2)
      {
         return my[n-1];
         //if(flip[n-1] && flip[n-2]){
         //}
      }
      else
         return 2;
   }

   // Betray -> count ++
   if(n>29 && VIP_3){
      for(int i=30; i<=n; i++){
         if(oppo[i]==1) count++;
      }
   }

   if(n>95 && VIP_10){
      for(int i=96; i<=n; i++){
         if(oppo[i]==1) count++;
      }
   }

   // If it is VIP_10
   if(VIP_10 & count < 10){
      return 0;
   }

   //If it is VIP_3
   if(VIP_3 & count < 10){
      return 0;
   }

   return 1;
}
};
