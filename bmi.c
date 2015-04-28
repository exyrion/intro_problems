/*Justin Liang
  4/11/11 */

#include <stdio.h>
#include <math.h>

int main(void)
{
  float pounds, inches, kilograms, meters, BMI;

  printf("Enter pounds and inches: ");
  scanf("%f %f", &pounds, &inches);

  kilograms = 0.45359237*pounds;
  meters = 0.0254*inches;
  BMI  = (kilograms)/(meters*meters);

  printf("BMI is %0.1f \n", BMI);

  return 0;
}
