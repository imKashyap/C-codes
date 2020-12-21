#include <stdio.h>
void main()
{
	int row,i;
	printf("Rows:\n");
	scanf("%d",&row);
	for(i=1;i<=row;i++)
	{
		for(int sp=1;sp<=row-i;sp++)
			printf(" ");
		for(int j=1;j<=i;j++)
			printf("* ");
		printf("\n");
	}
	for(i=1;i<=row-1;i++)
	{
		for(int sp=1;sp<=i;sp++)
			printf(" ");
		for(int j=1;j<=row-i;j++)
			printf("* ");
		printf("\n");
	}
}
