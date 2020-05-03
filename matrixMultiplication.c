#include <stdio.h>
#include <stdlib.h>
#define maxrows 5

int i,j;
int input(int *a[maxrows], int, int );
int product(int *a[maxrows],int *b[maxrows],int *p[maxrows],int,int,int );
int display(int *a[maxrows], int,int );
int main()
{
	int r1,c1,r2,c2,row;
	printf("Enter No. of rows and columns of 1st matrix:\n");
	scanf("%d%d",&r1,&c1);
	printf("Enter No. of rows ans columns of 2nd Matrix:\n");
	scanf("%d%d",&r2,&c2);
	if(c1!=r2)
	{
		printf("Multiplication Not Possible\n");
		exit(0);
	}
	int *A[maxrows],*B[maxrows],*P[maxrows];
	for(row=0;row<r1;row++)
	{
		A[row]=(int *)malloc(c1*sizeof(int));
		P[row]=(int *)malloc(c2*sizeof(int));
	}
	for(row=0;row<r2;row++)
		B[row]=(int *)malloc(c2*sizeof(int));
	printf("Enter elements of 1st Matrix:\n");
	input(A,r1,c1);
	printf("Enter elements of 2nd Matrix:\n");
	input(B,r2,c2);
	product(A,B,P,r1,c2,c1);
	display(P,r1,c2);
	return 0;
}

int input(int *a[maxrows], int r, int c)
{
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
			scanf("%d",(*(a+i)+j));
	}
	return 0;
}


int display(int *a[maxrows], int r, int c)
{
	printf("Product Result:\n");
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
			printf("%d ",*(*(a+i)+j));
		printf("\n");
	}
	return 0;
}

int product(int *a[maxrows], int *b[maxrows], int *p[maxrows],int r, int c, int c1)
{
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			*(*(p+i)+j)=0;
			for(int k=0;k<c1;k++)
				*(*(p+i)+j)+=(*(*(a+i)+k)) * (*(*(b+k)+j));
		}
	}
	return 0;
}