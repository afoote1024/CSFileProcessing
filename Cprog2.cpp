
#include "stdafx.h"
#include "stdio.h"
#include "stdlib.h"
#include "time.h"
#include "string.h"

int main()
	{
		char fname[10], fname1[10];
		char lname[10], lname1[10];
		int age = 0, age1=0;

		FILE* binfile;
	
		
	binfile=fopen("binfile.bin", "wb");
	
		if(binfile == NULL)
		{
			printf("%s", "File Not Found");
			return 1;
		}
    printf("%s", "Enter First Name");
    scanf("%s",fname);
	printf("%s", fname);
	 printf("%s", "Enter Last Name");
    scanf("%s",lname);
	printf("%s", lname);
	 printf("%s", "Enter Age");
     scanf("%d",&age);
	printf("%d", age);
	fwrite(fname, sizeof(fname),1,binfile);
	fwrite(lname, sizeof(lname),1,binfile);
	fwrite(&age, sizeof(age),1,binfile);



	binfile=fopen("binfile.bin", "rb");
	
		if(binfile == NULL)
		{
			printf("%s", "File Not Found");
			return 1;
		}
	fread(fname1, sizeof(fname1),1,binfile);
	fread(lname1, sizeof(lname1),1,binfile);
	fread(&age1, sizeof(age1),1,binfile);
	printf("%s%s%d",fname1,lname1, age);
	//, lname1, age1);
	fflush(stdin);

	fclose(binfile);
}