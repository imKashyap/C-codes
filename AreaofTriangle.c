#include<stdio.h>
#include<math.h>
int main()
{
	float a,b,c,s,A;
	printf("Enter the sides of ∆ :");
	scanf("%f%f%f", &a,&b,&c);
	printf("%f , %f , %f\n", a,b,c);
	s = (a + b + c)/2;
	A = sqrt( s*(s-a)*(s-b)*(s-c));
	printf("Required Area of ∆: %f",A);
	return 0;
}