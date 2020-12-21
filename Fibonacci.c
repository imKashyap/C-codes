#include<stdio.h>
int main()
{
	int n,i,a=-1,b=1,c;
	printf("Enter the no of terms you want display:\n");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		c=a+b;
		a=b;
		b=c;
		printf("%5d",c); 
	}
}