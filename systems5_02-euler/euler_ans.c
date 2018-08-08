#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int sumSquareDifference(int);
int returnLCM(int);
int numTimesFactor(int, int);
int isPrime(int);

int main() {
  printf("Problem #5: %d\n", returnLCM(20));
  printf("Problem #6: %d\n", sumSquareDifference(100));
}

int sumSquareDifference(int max) {
  int sumSquares = 0;
  int sumNums = 0;
  int i;
  
  for(i=1; i<=max; i++){
    sumSquares += pow(i, 2);
    sumNums += i;
  }

  return abs(sumSquares - pow(sumNums, 2));
}

/* Returns LCM of numbers [1, 2, ..., max] */
int returnLCM(int max){
  int i, j;
  int LCM = 1;

  /* Iterates through possible factors */
  for(i=1; i<=max; i++){
    if(isPrime(i)){
      int maxNum = 0;
      
      /* Checks to see if each num is divisible by prime factor */
      for(int j=1; j<=max; j++){
	int numFactors = numTimesFactor(j, i);
	if(numFactors > maxNum)
	  maxNum = numFactors;
      }

      LCM *= pow(i, maxNum);
    }
  }

  return LCM;
}

// return number of times factor goes into num
int numTimesFactor(int num, int factor){
  int numTimes = 0;
  
  while(num % factor == 0){
    num /= factor;
    numTimes++;
  }

  return numTimes;
}

int isPrime(int num){
  int i;
  
  if(num == 1)
    return 0;
  
  for(i=2; i<=num; i++){
    if(num % i == 0 && num != i)
      return 0;
  }
  
  return 1;
}
