#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <errno.h>   // for errno
#include <limits.h>  // for INT_MAX

void sieve(unsigned int max_number,bool *primes)
{
  int i=0, j=0;
  printf("\nmax_number is %d", max_number);

  if(max_number < 2) return;

  for(i=2; i<=max_number; i++) {
    if(primes[i]) {
      for(j= i*i; j <= max_number; j+=i) {
        primes[j] = false;
      }
    }
  }
  printf("\nPrime numbers from 1 to %d are: ", max_number);
  for(i=2; i<=max_number; i++) {
    if(primes[i] == true) printf("%d, ", i);
  }
  printf("\n");
}

int main(int argc, char **argv)
{
  char *p;
  int num = 0;

  //errno = 0;
  long conv = strtol(argv[1], &p, 10);
  if (errno != 0 || *p != '\0' || conv > INT_MAX) {
    printf("\nconversion to long has failed.\n");
    return(-1);
  }
  else {
    // No error
    num = conv;
    printf("\nmax number is %d", num);
  }
  bool primes[num];
  for (int i=0; i<num; i++) {
    primes[i] = true;
  }
  sieve(num, primes);
  return 0;
}
