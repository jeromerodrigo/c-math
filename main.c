#include <stdio.h>
#include <stdlib.h>
#include "arithmetic.h"
#include "matrices.h"
#include "physics.h"
void clearBuffer();
void colours();
int main()
{
	int ct = 0;
	short int errCount = 0; //Counter var for menus
	char buf[256]; //Buffer		

	//system("color 79");
	/* K. Lawless, 2010.
	Color Codes:
	* 0 = Black
	* 1 = Blue
	* 2 = Green
	* 3 = Aqua
	* 4 = Red
	* 5 = Purple
	* 6 = Yellow
	* 7 = White
	* 8 = Gray
	* 9 = Light Blue
	* A = Light Green
	* B = Light Aqua
	* C = Light Red
	* D = Light Purple
	* E = Light Yellow
	* F = Bright White
	*/

	while(1)
	{
		printf("---------------------\n");
		printf("||   MATHEMATICS   ||\n");
		printf("---------------------\n");

		printf("\n\t1. Arithmetic and Conversions\n\t2. Matrices\n\t3. Physics\n\n\tPress '4' to change terminal colours\n\tPress '5' to exit the program.\n");	

		gets(buf); //Reads string and puts into buffer
		ct = atoi(buf);  //Parse an integer value from buffer

		if(ct == 5)
			return 0;

		if(ct == 1 || ct == 2 || ct == 3 || ct == 4)
		{
			switch (ct)
			{
			case 1:
				system("cls");
				arithmetic();
				break;
			case 2:
				system("cls");
				matrices();
				break;
			case 3:
				system("cls");
				physics();
				break;
			case 4:
				system("cls");
				colours();
				break;
			default:
				printf("\n[INFO]Runtime error.\n\n");
				break;
			}
		}
		else
		{
			printf("\n[INFO]Input error.\n\n");
			errCount++;
		}
		
		if(errCount == 3)
		{
			printf("\n[INFO]Please input the number of your choice.\nUsage: < 1, 2, 3, 4>\n\n");
			errCount = 0;
		}
		clearBuffer();
	}

}
void colours()
{
	char choice[100];
	int x;
	short int ct = 1;

	printf("Change Terminal Colours\n");
	printf("=======================\n\n");

	printf("Choose a colour combination (Input number as selection):\n");
	printf("\t1. Red text & White background\n");
	printf("\t2. Green text & Yellow background\n");
	printf("\t3. Green text & Black background\n");
	printf("\t4. Blue text & Grey background\n");
	printf("\t5. Set to default colours (Grey text & Black background)\n");
	printf("\t6. Exit/Continue\n");

	printf("Input your choice: ");
	gets(choice);
	x = atoi(choice);

	if(x == 1 || x == 2 || x == 3 || x == 4 || x == 5 || x == 6)
	{
		switch(x)
		{
		case 1:
			system("color FC");
			break;
		case 2:
			system("color EA");
			break;
		case 3:
			system("color 0A");
			break;
		case 4:
			system("color 79");
			break;
		case 5:
			system("color 07");
			break;
		case 6:
			break;
		default:
			printf("Runtime Error\n");
		}
	}
	else
	{
		printf("[INFO] Input Error. Usage: < 1, 2, 3, 4 or 5>\n\n");
	}

}