/*

*this program gives the solution for 
 definite integral from 0 to 1 of log(1 + x)dx 
 using simpsons rule

*the interval [a,b] is divided into 2n intervals
 each of length h

*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/**** declaring functions here ****/

float f(float x);

/****main function starts here ****/

int main()
{
  float h, a = 0, b = 1, ans = 0;
  int   n, i;

  printf("Enter h (interval length) value : ");
  scanf("%f", &h);
  
  n = (b-a)/(2*h);

  for (i = 1; i < 2*n; i++)
  {
    if (i % 2 == 0)
      ans += 2*f(a + i*h);   
    else 
      ans += 4*f(a + i*h); 
  }
 
  ans = (h/3)*(f(a) + f(b) + ans);  

  printf("the answer is %f\n", ans);

  exit(0);
}

/**** f(x) function starts here ****/

float f(float x)
{
  return log(1 + x);
}
