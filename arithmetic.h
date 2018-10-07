#include<stdio.h>
#include<string.h>					// header declaration
#include<conio.h>
#include<stdlib.h>
int hexadd();
int hexsub();
int Bin2Dec();
int Bin2Hex();

int arithmetic()
{
	int opt = 0, n;

	while(1)
	{
		
		printf("     Arithmetic and Conversions     \n");
		printf("====================================\n");
		printf(" 1. Binary to decimal conversion\n");
		printf(" 2. Binary to hexadecimal conversion\n");
		printf(" 3. Hexadecimal addition\n");
		printf(" 4. Hexadecimal subtraction\n");               //  MAIN MENU
		printf(" 5. Exit\n");
		scanf(" %d", &opt);

		switch(opt)
		{
		case 1:
			system("cls");
			printf("Press 1 and ENTER to start\n");
			if(scanf("%d", &n) !=0)
				Bin2Dec(n);                             // OPTION 1
			else printf("\nNot allowed");
			break;
		case 2:
			system("cls");
			printf("Press 2 and ENTER to start\n");
			if(scanf("%d", &n) !=0)
				Bin2Hex(n);                              // OPTION 2
			else printf("\nNot allowed");
			break;
		case 3:
			system("cls");
			hexadd();
			break;
		case 4:
			system("cls");
			hexsub();
			break;
		case 5:
			system("cls");
			return 0;
			break;
		default:
			printf("Invalid Option Selected\n");
		}
	}
}
int hexadd()
{
	int first = 0;
	int second = 0;
	int total = 0;

	printf("Please enter the first decimal number\n");
	scanf("%d", &first);
	printf("The hexadecimal equivalent is : %04X\n\n\n",first);

	printf("Please enter the second decimal number\n");						// HEXADECIMAL ADDITION
	scanf("%d", &second);
	printf("The hexadecimal equivalent is :%04X\n\n\n", second);


	total=first+second;

	printf("The total is : %04X\n\n\n",total);


	system("pause");
}
int hexsub()

{
	int first=0;
	int second=0;
	int total=0;



	printf("Please enter the first decimal number\n");
	scanf("%d", &first);
	printf("The hexadecimal equivalent is : %04X\n\n\n",first);

	printf("Please enter the second decimal number\n");                       // HEXADECIMAL SUBTRACTION
	scanf("%d", &second);
	printf("The hexadecimal equivalent is : %04X\n\n\n", second);


	total=first-second;

	printf("The difference is : %04X\n\n\n",total);


	system("pause");
}
int Bin2Dec()
{
	int b=0,a[10],i=0,t=0;
	long long int n;


	printf("Conversion from Binary to Decimal\n");
	printf("\n");
	printf("Enter an Binary Number(max 8 digits only): ");                                   // Binary INPUT
	scanf("%lld",&n);


	while(n!=0)
	{
		a[i]=n%10;
		n=n/10;

		if(a[i]!=1 && a[i]!=0)                             // Converting binary strings to decimal
			t=1;
		i++;
	}

	a[i]=2;
	n=1;


	for(i=0;a[i]!=2;i++)
	{

		b=b+a[i]*n;
		n=n*2;
	}
	if(t==0)
		printf("Decimal Equivalent is %d\n\n\n",b);
	else if(t==1)
		printf("Number entered is not binary\n");                     // Decimal OUTPUT
}
int Bin2Hex()
{
	int i=0,a[5],t=0;
	long int n;

	printf("Converting from binary 2 hexadecimal\n\n\n");          // Binary number INPUT

	printf("Enter a binary number (max 8 digits only)\n");

	scanf("%ld", &n);

	while(n!=0)
	{
		a[i]=n%10000;
		n=n/10000;
		if(a[i]>1111)                 
			t=1;
		i++;
	}

	i--;
	if(t==0)
		for (;i>=0;i--)
		{
			switch(a[i])
			{
			case 0:
				printf("0");
				break;
			case 1:
				printf("1");
				break;                         // Converting Binary to Hexadecimal
			case 10:
				printf("2");
				break;
			case 11:
				printf("3");
				break;
			case 100:
				printf("4");
				break;
			case 101:
				printf("5");
				break;
			case 110:
				printf("6");
				break;
			case 111:
				printf("7");
				break;
			case 1000:
				printf("8");
			case 1001:
				printf("9");
				break;
			case 1010:
				printf("A");
				break;
			case 1011:
				printf("B");
				break;
			case 1100:
				printf("C");
				break;
			case 1101:
				printf("D");
				break;
			case 1110:
				printf("E");
				break;
			case 1111:
				printf("F");
				break;
			default:
				printf("The number is not binary\n");
				break;
			}

		}
		if(t==1)
			printf("The number is not binary\n");
		getch();
		system("pause");
}