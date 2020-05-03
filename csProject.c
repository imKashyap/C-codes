#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define my_file data.txt 

typedef struct
{
	char name[20];
	long PhoneNumber;
} entry;

//append function
void appendData()
{
	FILE *fp;
	entry obj;
	fp = fopen("my_file", "a");
	printf("*****ADD RECORD*****");
	printf("\n\nEnter name : ");
	scanf("%s", obj.name);
	fflush (stdin);
	printf("\nEnter telephone number: ");
	scanf("%ld", &obj.PhoneNumber);
	fflush(stdin);
	fprintf(fp, "%20s %10ld", obj.name, obj.PhoneNumber);
	printf("\n");
	fclose(fp);
}

//searching function
void searchRecord()
{
	entry obj;
	char name[20];
	FILE *fp;
	fp = fopen("my_file", "r");
	printf("\n***Displaying specific records***");
	printf("\n\nEnter name :");
	scanf("%s", name);
	int totrec =0;
	while (!feof(fp))
	{
		fscanf(fp, "%20s %10ld", obj.name, &obj.PhoneNumber);
		if (strcmp(obj.name, name)==0)
		{
			printf("\n\tName : %s\n", obj.name);
			printf("\tTelephone number : %ld\n", obj.PhoneNumber);
			totrec++;
		}
	}
	if (totrec ==0)
		printf("\nNo such name found in directory...");
	else 
		printf("\n\t%d entries found\n", totrec);
	fclose(fp);
	fflush(stdin);
	getchar();
}

// to show all records
void allRecords()
{
	fflush(stdin);
	FILE *fp;
	entry obj;
	system("cls");
	fp = fopen("my_file", "r");
	printf("\n***DISPLAYING ALL ENTRIES***");
	printf("\n\n\n\tName\t\t\tTelephone \n");
	printf("\t+======+\t\t+==========+\n");

	while (!feof(fp))
	{
		fscanf(fp, "%20s %10ld", obj.name, &obj.PhoneNumber);
		printf("\n\t%s\t\t\t%ld\n", obj.name, obj.PhoneNumber);
	}
	fclose(fp);
	printf("\n");
	getchar();
}

// main function
int main()
{
	char flag;
	int p = 1; //for loop condition
	while (p)
	{
		system("cls");
		printf("\n******TELEPHONE_DIRECTORY******");
		printf("\n\n1.) append data\n");
		printf("2.) find record\n");
		printf("3.) show all records\n");
		printf("4.) exit\n\n");
		printf("Choose response:");
		flag = getchar();
		fflush(stdin);
		system("cls");
		switch (flag)
		{
		case '1': //calling appendData function
			appendData();
			break;
		case '2': //calling searchRecord function
			searchRecord();
			break;
		case '3': //calling allRecords function
			allRecords();
			break;
		case '4': //to terminate loop
			p=0;
			printf("Program terminating  :)");
			break ;
		default :
			printf("invalid choice");
			break ;
		}fflush(stdin);
	}return 0;
}