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

	// add code to open file - DisneyMovies.txt
	
			
	   int ch = fgetc(txtfile);
		while(ch != EOF)
		{
			rec[recct][x] = ch; 
			if (rec[recct][x] == ',')
			{
				rec[recct][x] = '\0';
				x = 0;
				recct++;
			}
			else
			{
				x++;
			}
		 
	// add code to read next char  in file
		}

		rec[recct][x] = '\0';
		
	//	close file ?? - fclose(txtfile);
		
		printf("%s", "\nDisney Movies\n");
				
		for (int x=0; x < 10; x++)
		{
		printf("%c%d%c",'\n', x+1, ' ');
			 printf("%s", rec[x]);
		}
		
	// random select one Movie title
		int randtitle = rand() % 10;
		printf("%s", "\nFirst Character of Title ");
		printf("%c%c", rec[randtitle][0], '\n');

	// User guessing title process
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
	// Letter not found
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

	//  open file??

	//  random num gen again - randtitle = rand() % 10;
		int StringStart [] = {0,11,19,25,34,40,49,59,65,76};
	
	// add code to fseek to find title
    // check for error
		
	// add code to display current position
		
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
	//add code to close the file and end the program
		return 0;
}// end of main


