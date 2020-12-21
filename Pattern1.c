#include <stdio.h>
void main()
{
	int j;
	printf("Enter No. of rows:\n");
	scanf("%d",&j);
	for(int i=j;i!=0;i--)
	{
		int c=64+i,k;
		for(k=65;k<=c;k++)
		printf("%c",(char)k);
		if(i<j)
		{
			int r=j-i+1;
			r=2*r-3;
			k-=1;
			for(int sp=1;sp<=r;sp++)
			printf(" ");
		}
		else
		k-=2;
		while(k>=65)
		{
			printf("%c",(char)k);
			k--;
		}
		printf("\n");
	}		
}
    
