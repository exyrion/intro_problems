/*Justin Liang
  4/11/11 */

#include <stdio.h>
#include <math.h>

int main(void)
{
  float value, base, answer;
  printf("Enter value and desired base: ");
  scanf("%f %f", &value, &base);

  answer = log10(value)/log10(base);

  printf("Log of %0.1f to base %0.0f is %0.1f\n", value, base, answer);
  return 0;
}
