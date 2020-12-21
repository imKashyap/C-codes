#include <stdio.h>
void main()
{
	int n1,n2,lcm,temp;
	printf("ENTER TWO NUMBERS:\n");
	scanf("%d%d",&n1,&n2);
	lcm=n1*n2;
	printf("The HCF and LCM of %d and %d are ",n1,n2);
	if(n2>n1)
	{
		temp=n1;
		n1=n2;
		n2=temp;		
	}
	while(n2)
	{
		temp=n2;
		n2=n1%n2;
		n1=temp;
	}
	printf("%d and %d respectively. \n",n1,(lcm/n1));
}