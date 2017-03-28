// CFiletxt : Defines the entry point for the console application.
//
#include "stdafx.h"
#include "stdio.h"
#include "stdlib.h"
#include "time.h"
#include "string.h"

int main()
	{
	char rec [10] [16];
	int recct = 0;
	int recx=0;
	int x = 0;
	int incorrect;
	bool ansfound = false;
	srand(time(NULL));

	FILE* txtfile;
	
	txtfile=fopen("DisneyMovies.txt","r");
		if(txtfile == NULL)
		{
			printf("%s", "File Not Found");
			return 1;
		}
	
			
	   int ch = fgetc(txtfile);
		while(ch != EOF)
		{
			rec[recct][x] = ch; 
			if(rec[recct][x] == ',')
			{rec[recct][x] = '\0';
			x=0;
			recct++;
			}
			else
				x++;
		 
		ch=fgetc(txtfile);
		}

		rec[recct][x] = '\0';
		
	//	fclose(txtfile);
		
		printf("%s", "\nDisney Movies\n");
		printf("%s", " \nFile Read\n");
	
		
		for (int x=0; x < 10; x++)
		{
		printf("%c%d%c",'\n', x+1, ' ');
			 printf("%s", rec[x]);
		}
		

		int randtitle = rand() % 10;
		printf("%s", "\nFirst Character of Title ");
		printf("%c%c", rec[randtitle][0], '\n');
		char ans = ' ';
		char checkstr[20];
		x = 1;
		incorrect =0;
		char ansstring[20];
		while (incorrect < 3 && x < strlen(rec[randtitle]))
		{
		printf("%s","\nSelect a letter");
		scanf("%s", ansstring);
		ans = ansstring[0];
		//ans=fgetc(stdin);
		//ans1 = fgetc(stdin);
	

	// search title for entered character
		checkstr[0] = rec[randtitle][0];
		checkstr[strlen(rec[randtitle])] = '\0';
		ansfound = false;
		for (int a = 1; a < strlen(rec[randtitle]); a++)
		{
			
			if (ans == rec[randtitle][a])
			{
				checkstr[a] = ans;
				x++;
				ansfound = true;
				printf("%s%d", " \n Character found at ", a+1);
			}
		}
	
		if (!ansfound)
		{
		incorrect++;
		printf("%s%d","\nCharacter Not found in Title Count - ", incorrect);
		}
		} // end of while

// Find the Title?
		checkstr[x] = '\0';
		if (strcmp(rec[randtitle],checkstr)==0)
			printf("%s","\nPerfect match");
		else
		{
			if (x >= strlen(rec[randtitle]))
			    printf("%s","\nNo match - Too many Characters enterred");
			else
				printf("%s","\nNo match - Too many Characters Not Found");
		}

	

		// Random Read
		printf("%s", "\n\nRandom Read\n");

	/*	txtfile=fopen("DisneyMovies.txt","r");
		if (txtfile == NULL)
		{
			printf("%s", "File Not Found");
			return 1;
		}
		*/

		//randtitle = rand() % 10;
		int StringStart [] = {0,11,19,25,34,40,49,59,65,76};
		if (fseek(txtfile,sizeof(char)*StringStart[randtitle],
			SEEK_SET) !=0)
			{
				printf("%s", "Error in fseek at Beginning of file");
				return 1;
			}
		//rewind(txtfile);
		int currpos = ftell(txtfile);
		printf("%s%d%c", "Current position ",currpos, '\n');
		
		ch = fgetc(txtfile);
		x =0;
		 
		while(ch != ','&& ch != EOF)
		{
			checkstr[x] = ch; 
			ch=fgetc(txtfile);
			x++;
		}
			checkstr[x] = '\0';
		
		printf("%s%c", checkstr, '\n');
		fclose(txtfile);
		return 0;
}// end of main


