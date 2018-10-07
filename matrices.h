#include <stdio.h>
#include <stdlib.h>

int add()
{
	int row, col;
	short int i, j, k;
	int ** result; //Declare resultant matrix
	int *** matrix;

	printf("Insert number of rows: ");
	scanf("%d", &row);
	
	printf("Insert number of columns: ");
	scanf("%d", &col);
	
	/*START DYNAMIC ALLOCATION*/
	matrix = (int ***)malloc(2 * sizeof(int**));
	for(i = 0; i < 2; i++)
	{
		matrix[i] = (int **)malloc(row * sizeof(int*));

		for(j = 0; j < row; j++)
		{
			matrix[i][j] = (int *)malloc(col * sizeof(int));
		}
	}
	/*END DYNAMIC ALLOCATION*/
	printf("\n[INFO] Memory Allocated for matrices.\n");
	/*START INITIALIZATION*/
	for(i = 0; i < 2; i++)
	{
		for(j = 0; j < row; j++)
		{
			for(k = 0; k < col; k++)
			{
				matrix[i][j][k] = 0;
			}
		}
	}
	/*END INITIALIZATION*/

	printf("\n[INFO] Initialization 1 complete.\n");

	/*START USER IN*/
	for(i = 0; i < 2; i++)
	{
		printf("Matrix %d\n", i+1);
		printf("=========\n\n");
		printf("[INFO] Press ENTER after input a integer at specified coordinates\n\n");
		
		for(j = 0; j < row; j++)
		{
			for(k = 0; k < col; k++)
			{
				printf("Input at (%d,%d): ", j, k);
				scanf("%d", &matrix[i][j][k]);
			}
		}
		printf("\n");
	}
	/*END USER IN*/

	/*START DYNAMIC ALLOCATION*/
	result = (int **)malloc(row * sizeof(int*));
	for(i = 0; i < row; i++)
		result[i] = (int *)malloc(col * sizeof(int));
	/*END DYNAMIC ALLOCATION*/

	printf("\n[INFO] Memory Allocated for result.\n");

	/*START INITIALIZATION*/
	for(i = 0; i < row; i++)
	{
		for(j = 0; j < col; j++)
			result[i][j] = 0;
	}
	/*END INITIALIZATION*/

	printf("\n[INFO] Result matrix initialized.\n");

	/*START ADDITION*/
	for(i = 0; i < 2; i++)
	{
		for(j = 0; j < row; j++)
		{
			for(k = 0; k < col; k++)
				result[j][k] += matrix[i][j][k];
		}
	}
	/*END ADDITION*/
	
	/*START PRINT RESULT*/
	printf("\nResultant Matrix\n");
	printf("================\n\n");

	for(i = 0; i < row; i++)
	{
		for(j = 0; j < col; j++)
			printf(" %d ", result[i][j]);
		printf("\n");
	}
	/*END PRINT RESULT*/

	/*START FREE ALLOCATION*/
	for(i = 0; i < 2; i++)
	{
		for(j = 0; j < row; j++)
		{
			free(matrix[i][j]);
		}
		free(matrix[i]);
	}
	free(matrix);

	for(i = 0; i < row; i++)
	{
		free(result[i]);
	}
	free(result);
	/*END FREE ALLOCATION*/

	printf("\n[INFO] Memory freed.\n\n");

	return 0;
}
int sub()
{
	int row, col;
	short int i, j, k;
	int ** result; //Declare resultant matrix
	int *** matrix;

	printf("Insert number of rows: ");
	scanf("%d", &row);
	
	printf("Insert number of columns: ");
	scanf("%d", &col);
	
	/*START DYNAMIC ALLOCATION*/
	matrix = (int ***)malloc(2 * sizeof(int**));
	for(i = 0; i < 2; i++)
	{
		matrix[i] = (int **)malloc(row * sizeof(int*));

		for(j = 0; j < row; j++)
		{
			matrix[i][j] = (int *)malloc(col * sizeof(int));
		}
	}
	/*END DYNAMIC ALLOCATION*/
	printf("\n[INFO] Memory Allocated for matrices.\n");
	/*START INITIALIZATION*/
	for(i = 0; i < 2; i++)
	{
		for(j = 0; j < row; j++)
		{
			for(k = 0; k < col; k++)
			{
				matrix[i][j][k] = 0;
			}
		}
	}
	/*END INITIALIZATION*/

	printf("\n[INFO] Initialization 1 complete.\n");

	/*START USER IN*/
	for(i = 0; i < 2; i++)
	{
		printf("Matrix %d\n", i+1);
		printf("=========\n\n");
		printf("[INFO] Press ENTER after input a integer at specified coordinates\n\n");

		for(j = 0; j < row; j++)
		{
			for(k = 0; k < col; k++)
			{
				printf("Input at (%d,%d): ", j, k);
				scanf("%d", &matrix[i][j][k]);
			}
		}
		printf("\n");
	}
	/*END USER IN*/

	/*START DYNAMIC ALLOCATION*/
	result = (int **)malloc(row * sizeof(int*));
	for(i = 0; i < row; i++)
		result[i] = (int *)malloc(col * sizeof(int));
	/*END DYNAMIC ALLOCATION*/

	printf("\n[INFO] Memory Allocated for result.\n");

	/*START INITIALIZATION*/
	for(i = 0; i < row; i++)
	{
		for(j = 0; j < col; j++)
			result[i][j] = 0;
	}
	/*END INITIALIZATION*/

	printf("\n[INFO] Result matrix initialized.\n");

	/*START SUBTRACTION*/
	
	for(j = 0; j < row; j++)
	{
		for(k = 0; k < col; k++)
			result[j][k] = matrix[0][j][k] - matrix[1][j][k];
	}
	
	/*END SUBTRACTION*/
	
	/*START PRINT RESULT*/
	printf("\nResultant Matrix\n");
	printf("================\n\n");

	for(i = 0; i < row; i++)
	{
		for(j = 0; j < col; j++)
			printf(" %d ", result[i][j]);
		printf("\n");
	}
	/*END PRINT RESULT*/

	/*START FREE MEMORY*/
	for(i = 0; i < 2; i++)
	{
		for(j = 0; j < row; j++)
		{
			free(matrix[i][j]);
		}
		free(matrix[i]);
	}
	free(matrix);

	for(i = 0; i < row; i++)
	{
		free(result[i]);
	}
	free(result);
	/*END FREE MEMORY*/

	printf("\n[INFO] Memory freed.\n\n");

	return 0;
}
int multi()
{
	short int i, j, k, x;
	int rowCol[2][2];
	int * temp;
	int ** result; //Declare resultant matrix
	int *** matrix;

	printf("===================\n");
	printf("| Multiplication  |\n");
	printf("===================\n");

	//Get rows and columns
	for(i = 0; i < 2; i++)
	{
		printf("Matrix %d\n", i+1);
		printf("=========\n");

		printf("Insert number of rows: ");
		scanf("%d", &rowCol[i][0]);

		printf("Insert number of columns: ");
		scanf("%d", &rowCol[i][1]);
	}

	/*START temp ALLOCATION*/
	temp = (int*)malloc(rowCol[0][1]*sizeof(int));
	/*END temp ALLOCATION*/

	//Check if matrices are compatible
	if(rowCol[0][1] != rowCol[1][0])
	{
		printf("[WARNING] Matrix dimensions are not compatible! Exiting...\n");
		return 0;
	}

	/*START DYNAMIC ALLOCATION*/
	matrix = (int***)malloc(2*sizeof(int**));
	
	for(i = 0; i < 2; i++)
	{
		matrix[i] = (int**)malloc(rowCol[i][0]*sizeof(int*));
		
		for(j = 0; j < rowCol[i][0]; j++)
		{
			matrix[i][j] = (int*)malloc(rowCol[i][1]*sizeof(int));
		}
	}
	/*END DYNAMIC ALLOCATION*/

	printf("\n[INFO] Memory allocation for matrix[][][] complete!\n");

	/*START INIT MATRIX*/
	for(i = 0; i < 2; i++)
	{
		for(j = 0; j < rowCol[i][0]; j++)
		{
			for(k = 0; k < rowCol[i][1]; k++)
				matrix[i][j][k] = 0;
		}
	}
	/*END INIT MATRIX*/

	printf("\n[INFO] matrix[][][] initialized!\n");

	/*START RESULT ALLOCATION*/
	result = (int**)malloc(rowCol[0][0]*sizeof(int*));
	for(i = 0; i < rowCol[0][0]; i++)
	{
		result[i] = (int*)malloc(rowCol[1][1]*sizeof(int));
	}
	/*END RESULT ALLOCATION*/

	printf("\n[INFO] Memory allocation for result[][] complete!\n");

	/*START INIT RESULT*/
	for(i = 0; i < rowCol[0][0]; i++)
	{
		for(j = 0; j < rowCol[1][1]; j++)
		{
			result[i][j] = 0;
		}
	}
	/*END INIT RESULT*/

	printf("\n[INFO] result[][] initialized!\n");

	/*START USER IN*/
	for(i = 0; i < 2; i++)
	{
		printf("Matrix %d\n", i+1);
		printf("=========\n");
		printf("[INFO] Press ENTER after input a integer at specified coordinates\n\n");

		for(j = 0; j < rowCol[i][0]; j++)
		{
			for(k = 0; k < rowCol[i][1]; k++)
			{
				printf("Insert a value at (%d,%d): ", j+1, k+1);
				scanf("%d", &matrix[i][j][k]);
			}
		}
		printf("\n");
	}
	/*END USER IN*/

	/*START MULTI*/
	for(x = 0; x < rowCol[1][1]; x++)
	{
		for(i = 0; i < rowCol[0][0]; i++)
		{
			//Multiplying matrices
			for(j = 0; j < rowCol[1][0]; j++)
			{
				temp[j] = matrix[0][i][j] * matrix[1][j][x];
			}

			//Adding values in temp together >> result
			for(k = 0; k < rowCol[0][1]; k++)
			{
				result[i][x] += temp[k];
			}
		}
	}
	/*END MULTI*/

	/*START PRINT RESULT*/
	printf("\nResultant Matrix\n");
	printf("==================\n\n");
	for(i = 0; i < rowCol[0][0]; i++)
	{
		for(j = 0; j < rowCol[1][1]; j++)
		{
			printf(" %d ", result[i][j]);
		}
		printf("\n\n");
	}
	printf("\n\n");
	/*END PRINT RESULT*/

	/*START FREE MEMORY*/
	for(i = 0; i < 2; i++)
	{
		for(j = 0; j < rowCol[i][0]; j++)
		{
			free(matrix[i][j]);
		}
		free(matrix[i]);
	}
	free(matrix);

	for(i = 0; i < rowCol[0][0]; i++)
	{
		free(result[i]);
	}
	free(result);

	free(temp);
	/*END FREE MEMORY*/

	printf("\n[INFO] Memory freed!\n");

	return 0;
}
int scalar()
{
	int i, j, fact;
	int ** matrix;
	int row, col;

	//Get rows and columns
	printf("Matrix\n");
	printf("=========\n");

	printf("Insert number of rows: ");
	scanf("%d", &row);

	printf("Insert number of columns: ");
	scanf("%d", &col);

	/*START ALLOCATE MATRIX*/
	matrix = (int **)malloc(row*sizeof(int*));
	for(i = 0; i < row; i++)
	{
		matrix[i] = (int *)malloc(col*sizeof(int));
	}
	/*END ALLOCATE MATRIX*/

	printf("\n[INFO] Matrix allocated!\n");

	/*START INIT MATRIX*/
	for(i = 0; i < row; i++)
	{
		for(j = 0; j < col; j++)
		{
			matrix[i][j] = 0;
		}
	}
	/*END INIT MATRIX*/

	printf("\n[INFO] Matrix initialized!\n");

	/*START USER IN*/
	printf("Insert the scalar factor: ");
	scanf("%d", &fact);

	printf("Input the matrix\n");
	printf("================\n\n");
	printf("[INFO] Press ENTER after input a integer at specified coordinates\n\n");
	for(i = 0; i < row; i++)
	{
		
		for(j = 0; j < col; j++)
		{
			printf("Insert value at (%d,%d): ", i+1, j+1);
			scanf("%d", &matrix[i][j]);
		}
	}
	printf("\n");
	/*END USER IN*/

	/*START MULTI SCALAR*/
	for(i = 0; i < row; i++)
	{
		for(j = 0; j < col; j++)
		{
			matrix[i][j] *= fact;
		}
	}
	/*END MULTI SCALAR*/

	/*START PRINT MATRIX*/
	printf("\nResultant Matrix\n");
	printf("==================\n\n");
	for(i = 0; i < row; i++)
	{
		for(j = 0; j < col; j++)
			printf(" %d ", matrix[i][j]);
		printf("\n");
	}
	/*END PRINT MATRIX*/

	/*START FREE MEMORY*/
	for(i = 0; i < row; i++)
	{
		free(matrix[i]);
	}
	free(matrix);
	/*END FREE MEMORY*/

	printf("\n[INFO] Memory freed!\n");

	return 0;
}
void clearBuffer()
{
	int c;
	printf("[INFO] Press ENTER if program pauses.\n");
	/*Read until the end of line or end of file*/
	while ((c = fgetc(stdin)) != '\n' && c != EOF);
	printf("[INFO] Buffer Cleared!\n\n");
	clearerr(stdin);
}
int matrices()
{
	char buf[100];
	short int ct, i, j;
	
	while(1)
	{
		
		printf("--------------\n");
		printf("|  MATRICES  |\n");
		printf("--------------\n");

		printf("1. Addition\n2. Subtraction\n3. Multiplication\n4. By scalar\n5. To Main Menu\n\n");
		printf("Input your choice of operation: ");
		fgets(buf, sizeof(buf), stdin);
		ct = atoi(buf);
		
		if(ct == 5)
		{
			system("cls");
			return 0;
		}

		if(ct == 1 || ct == 2 || ct == 3 || ct == 4)
		{
			switch(ct)
			{
				case 1:
					system("cls");
					add();
					break;
				case 2:
					system("cls");
					sub();
					break;
				case 3:
					system("cls");
					multi();
					break;
				case 4:
					system("cls");
					scalar();
					break;
				default:
					printf("\n[WARNING] Runtime Error! Exiting...\n");
					break;
			}
		}
		else
			printf("[INFO] Pls input one of the options:\n < 1, 2, 3, 4 or 5 >\n\n");
		clearBuffer();
	}
	
}