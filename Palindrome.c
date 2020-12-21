#include <stdio.h>
void main()
{
	int up,lw,i,rev;
	printf("Enter the range:\n");
	scanf("%d%d",&lw,&up);
	printf("The following are palindrome nos. between %d and %d:\n",lw,up);
	for(i=lw;i<=up;i++)
	{
		rev=0;
		for(int k=i;k!=0;rev=rev*10+(k%10),k/=10);
		if(rev==i)
		printf("%d\n",i);
	}
}