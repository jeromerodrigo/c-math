#include <stdio.h>
#include <stdlib.h>

/* START CALC FUNCS */
float *momentum(float a, float b, float c)
{
	float x = 0.0;
	x = (a)*(b/c);
	return &x;
}
float *work(float m, float a0, float a1, float b0, float b1)
{
	float x;
	x = (float) (0.5)*(m)*(((a1/b1)*(a1/b1))-((a0/b0)*(a0/b0)));
	return &x;
}
float *energy(float m, float d, float t)
{
	float x;
	x = (float) (0.5)*(m)*(d)*(d)/((t)*(t));
	return &x;
}
/* END CALC FUNCS */
/*START MAIN FUNCS */
int momentum_main()
{
	
	int i, j, k;
	float mass, dist, time;
	float result = 0.0;
	float * mome = NULL; //Declare 1D Array
	
	printf("         MOMENTUM         \n");
	printf("--------------------------\n");
	
	printf ("Number of objects within the system: ");
	scanf ("%d", &j);

	
	mome = (float *) malloc(j * sizeof(float));
	
	for (i = 0; i < j; i++)
	{
		printf ("Mass of object %d (kilograms): ", i+1);
		scanf ("%f", &mass);
		
		printf ("Distance travelled of object %d (meters): ", i+1);
		scanf("%f", &dist);
		
		printf ("Time taken for object %d (seconds): ", i+1);
		scanf ("%f", &time);
		
		mome[i] = *momentum(mass, dist, time);
		
		printf("\n------------------------------\n\n");
		
	}
	
	for (k = 0; k < i ; k++) //Sum collecting loop
	{
		result += mome[k];
	}
	
	printf ("The total momentum of %d objects = %.2f kg.m/s\n\n\n", j, result); //Print the result
	
	return 0;
}
int work_main()
{
	float distAndTime[2][2] = { { 0.0, 0.0 }, { 0.0, 0.0 } };
	float massW = 0.0;
	float *result;
	
	printf("           WORK           \n");
	printf("--------------------------\n");
	
	printf ("Please input the mass of object (kilograms):");
	scanf ("%f", &massW);
	
	printf ("Please input the initial distance (meters):");
	scanf ("%f", &distAndTime[0][0]);
	printf ("Please input the final distance (meters):");
	scanf ("%f", &distAndTime[0][1]);
	
	printf ("Please input the initial time spent (seconds):");
	scanf ("%f", &distAndTime[1][0]);
	printf ("Please input the final time spent (seconds):");
	scanf ("%f", &distAndTime[1][1]);
	
	result = work(massW, distAndTime[0][0], distAndTime[0][1], distAndTime[1][0], distAndTime[1][1]);
	
	printf ("The workload of the object is %f kg.m^2/s^2\n\n\n", *result);
	
	return 0;
}
int energy_main()
{
	float distAndTime[2][2] = { { 0.0, 0.0 }, { 0.0, 0.0 } };
	float massW = 0.0;
	float *result;
	
	printf("          ENERGY          \n");
	printf("--------------------------\n");
	
	printf("Please input the mass of object (kilograms):");
	scanf("%f", &massW);
	
	printf("Please input the distance (meters):");
	scanf("%f", &distAndTime[0][0]);
	
	printf("Please input the time spent (seconds):");
	scanf("%f", &distAndTime[1][0]);
	
	result = energy(massW, distAndTime[0][0], distAndTime[1][0]); 
	
	printf("The energy of the object is %f kg.m^2/s^2\n\n\n", *result);
	
	return 0;
}
/* END MAIN FUNCS */
/* START PHYSICS MENU*/
int physics()
{
	short int choice = 0;
	char buf[256];

	while(1)
	{
		printf ("PHYSICS\n-------\n\nPlease choose which formula you want to calculate from the list below.\n1. Momentum\n2. Work\n3. Energy\n4. Main Menu\n\n");
		gets(buf);
		choice = atoi(buf);
		
		if(choice == 4)
			return 0;
		
		if(choice == 1 || choice == 2 || choice == 3)
		{

			printf ("\n");

			switch (choice)
			{
				case 1: //Momentum	
					system("cls");
					momentum_main();
					break;
				case 2: //Work
					system("cls");
					work_main();
					break;
				case 3: //Energy
					system("cls");
					energy_main();
					break;	
				default: 
					printf("Options: < 1, 2 or 3 >\n 4 to main menu.\n\n");
					break;
			}
			clearBuffer();
		}
		
	}
}
/*END PHYSICS MENU*/