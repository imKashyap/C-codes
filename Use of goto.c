#include <stdio.h>
#include <stdlib.h>
void main()
{
	int goals;
	printf("Enter No. of goals: \n");
	scanf("%d",&goals);
	if(goals>=5)
	goto end;
	else
	{
		printf("You need to improve.\n");
		exit(0);
	}
	end:printf("Good.Keep Going\n");
}