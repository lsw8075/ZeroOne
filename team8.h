


#include "strategy.h"
class team8 : public strategy {
public:


 int mypassword;
 int oppopassword;
 int detected = 0;

virtual int decision(const int my[], const int oppo[], const int flip[], const int res[], const int n) {
 if (n == 0) {
  return 1;
 }
 if (n == 1) {
  if (oppo[0] == 1) mypassword++;
  if (oppo[0] == 0) oppopassword++;
  return 0;
 }
 if (n == 2) {
  if (oppo[1] == 0) mypassword++;
  if (oppo[1] == 1) oppopassword++;
  return 0;
 }
 if (n == 3) {
  if (oppo[2] == 0) mypassword++;
  if (oppo[2] == 1) oppopassword++;
  return 1;
 }
 if (n == 4) {
  if (oppo[3] == 1) mypassword++;
  if (oppo[3] == 0) oppopassword++;
  return 0;
 }
 if (n == 5) {
  if (oppo[4] == 0) mypassword++;
  if (oppo[4] == 1) oppopassword++;
  return 1;
 }
 if (n == 6) {
  if (oppo[5] == 1) mypassword++;
  if (oppo[5] == 0) oppopassword++;
  return 1;
 }
 if (n == 7) {
  if (oppo[6] == 1) mypassword++;
  if (oppo[6] == 0) oppopassword++;
  return 1;
 }
 if (n == 8) {
  if (oppo[7] == 1) mypassword++;
  if (oppo[7] == 0) oppopassword++;
  return 0;
 }
 if (n == 9) {
  if (oppo[8] == 0) mypassword++;
  if (oppo[8] == 1) oppopassword++;
  return 0;
 }
 if (n == 10) {
  if (oppo[9] == 0) mypassword++;
  if (oppo[9] == 1) oppopassword++;
 }
 if (n >= 10) {
  if (n == 50) {
   detected = 0;
   return 0;
  }
  if (n == 11) return 0;
  if (n >= 50) {
   if (n < 60) return oppo[n - 1];
  }
  if (n >= 20) {
   if (oppo[n - 9] + oppo[n - 8] + oppo[n - 7] + oppo[n - 6] + oppo[n - 5] + oppo[n - 4] + oppo[n - 3] + oppo[n - 2] + oppo[n - 1] + oppo[n-10] >= 3) {
    detected = 1;
   }
  }
  if (detected) return 1;
  if (mypassword >= 9) {
   return 0;
  }
  if (oppopassword >= 9) {
   return 0;
  }
  if (n < 20) return oppo[n - 1];
  return 0;
 }
}


};
