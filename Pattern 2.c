#include <stdio.h>
int main()
{
	int row, c;
	printf("Rows:\n");
	scanf("%d",&row);
	for(int i=1;i<=row;i++)
	{
		for(int sp=1;sp<=row-i;sp++)
			printf(" ");
		for(int j=1,c=1;c!=0;j>=i?c--:c++,j++)
			printf("%d",c);
		printf("\n");
	}
	return 0;
}