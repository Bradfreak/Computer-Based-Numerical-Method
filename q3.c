/* This program finds the definite integral of log(1+x) with lower limit as a and upper limit as b using simpsons method.
Considering the base of log as e(natural logarithm).
Take input as h.
It decides how many sub intervals are to be formed.
If 2n are no of sub intervals then
 
   n = b-a/2h
   x_i = x0 + ih
   ans = h/3(f0 + 4(f1+f3+...f(2n-1)) + 2(f2+f4+...f(2n-2)) +f(2n))
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 100

/* Function Declaration */

double function(double);

/* Main starts here */

int main(void)
{

/* Declaring variables */

  double a; /* Lower bound of integral */
  double b; /* Upper bound of integral */
  double h; /* Length of each sub interval */
  double even; /* Value of f2+f4+...f(2n-2) */
  double odd; /* Value of f1+f3+...f(2n-1) */
  double ans; /* Final result */;
  int n = 0; /* No of sub intervals/2 */
  int i = 0; /* Temp variable to use in loops */
  int j = 1; /* Temp variable to use in loops */
  double x[MAX]; /* The values of x in an array */
  double fun[MAX]; /* The function values of x in an array */

/* Taking inputs */

  printf("Enter the lower integral 'a'\n");
  scanf("%lf", &a);

  printf("Enter the upper integral 'b'\n");
  scanf("%lf", &b);

  printf("Enter the value of h\n");
  scanf("%lf", &h);

  if (h < a || h > b || h == 0) { /* Checking if h is proper or not */
     printf("Enter proper value of h\n");
     exit(1);
  }

  n = (b-a)/(2*h); /* Finding no of subdivisions */

  while (i != (2*n + 1)) {
        x[i] = a + (i*h); /* Finding the x values */
	fun[i] = function(x[i]); /* Finding the function values */
	i++;
  }
  
  while (j != (2*n)+1) {
	odd = odd + fun[j]; /* Finding the sum of all odd placed function values */
	j= j+2;
  }

  j = 2;

  while (j != (2*n)) {
	even = even + fun[j]; /*Finding the sum of all even placed function values */
	j= j+2;
  }

  ans = ((function(x[0]) + 4*odd + 2*even + function(x[2*n]))*h)/3; /* Finding the answer */
  printf("The integration is %lf\n", ans); /*Printig the answe */
  exit (0);
}

/* This function finds the function value of a given value */

double function(double x)
{
  double f;

  f = log(1+x); /* Finding the function value */

  return f;
}

