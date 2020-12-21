#include<stdio.h>
int main()
{
	int n,a,b,c,d,e,f;
	printf("Enter the amount:");
	scanf("%d", &n);
	printf("%d\n",n);
	//number of Rs. 100 notes
	a = n/100;
	/*number of Rs. 50 notes
	  is the left ones devided by 50*/
	b = (n%100)/50;
	//similarly
	c = (n%50)/10;
	d = (n%10)/5;
	e = (n%5)/2;
	f = (n%5)%2;
	printf("The minimum number of notes required: %d",(a+b+c+d+e+f));

	return 0;
}