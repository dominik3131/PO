#include <stdio.h>
#include <stdlib.h>
#include <math.h>

FILE* openFile(char* name);
int closeFile(FILE *name);
int sizeMatrix(FILE *name);
double** allocateMatrix(int size);
void insertDataToMatrix(double** Matrix, FILE *name);
double detMatrix(double** Matrix,int size);
void closeMatrix(double** Matrix);
int main()
{
	char* name="matrix.txt";
	FILE *fp=openFile(name);
	int size=sizeMatrix(fp);
	double** matrix;
	if((matrix=allocateMatrix(size))==0)
	{
		closeFile(fp);
		puts("blad przy alokacji");
		exit(1);
	}
	insertDataToMatrix(matrix,fp);
	printf("%f",detMatrix(matrix,size));
	closeMatrix(matrix);
	return 0;
}

/* function opens file with matrix and returns pointer to opened file
name - name of file to open
matrix - pointer to file 
YOU NEED TO CLOSE FILE AFTER YOU END READING DATA!!!*/
FILE* openFile(char* name)
{
	FILE *matrix=fopen(name,"r");
	if(fopen==NULL)
	{
		puts("nie udalo sie otworzyc pliku");
		exit(1);
	}
	return matrix;
}

/* function closing file
name - pointer to file that needs to be closed
returns:
0 - file closed properly
1 - file couldn't be closed */
int closeFile(FILE *name)
{
	if(fclose(name)==EOF)
	{
		return 1;	
	}
	
	return 0;
}

/* gets size of matrix
name - name of file
size - size of matrix*/
int sizeMatrix(FILE *name)
{	
	fseek(name,0,SEEK_SET);
	int size;
	
	fscanf(name,"%d",&size);
	return size;
}

void closeMatrix(double** Matrix)
{
	free(Matrix[0]);
	free(Matrix);
}
/* allocates memory for matrix
size - size of matrix
wsk - array of pointers to pointers to double, holds matrix
returns pointer to matrix or 0 if error appeared and there is need to close the file
YOU NEED TO FREE MEMORY LATER !!!
*/
double** allocateMatrix(int size)
{
	
	// creating array of pointers to pointers to double
	double **wsk=(double**)malloc(size*sizeof(double*));
	if(wsk==NULL){
		free(wsk);
		return 0;
	}
	
	// creating array of pointers to double that holds matrix
	wsk[0]=(double*)malloc(size*size*sizeof(double));
	if(wsk[0]==NULL)
	{	
		free(wsk[0]);
		free(wsk);
		return 0;
	}	
		
	//filling wsk with pointers
	int i;
	for(i=0;i<size;i++)
	{
		wsk[i]=(*wsk+size*i);
	}
	return wsk;
}

/* gets data from file and inserts it to array holding matrix
Matrix - pointer to array
name - pointer to file
at the end closing file so you cant use it later without opening it again
*/
void insertDataToMatrix(double** Matrix, FILE *name)
{	
	int size,i,j;
	fseek(name,0,SEEK_SET);
	fscanf(name,"%d",&size); 
	for(i=0;i<size;i++)
	{
		for(j=0;j<size;j++)
		{
			fscanf(name,"%lf",&Matrix[i][j]); 
		}
	}
	closeFile(name);	
}


double detMatrix(double** Matrix,int size)
{
	double det = 0;
	

	if (size < 1)
	{
		puts("nie mozna policzyc wyznacznika");
		free(Matrix);
		exit(0);
	}
	
	else if (size == 1)
	{ 
		det = Matrix[0][0];
	}
	 
	else if (size == 2) 
	{
		det = Matrix[0][0] * Matrix[1][1] - Matrix[1][0] * Matrix[0][1];
	}
	
	else
	{
		int i,j,j1,j2;
		double **m = NULL;
      	det = 0;
      
      	for (j1=0;j1<size;j1++)
		{
        	m = allocateMatrix(size-1);
			for (i=1;i<size;i++)
		 	{
            	j2 = 0;
            	for (j=0;j<size;j++)
				{
               		if (j == j1)	continue;
               		
					m[i-1][j2] = Matrix[i][j];
               		j2++;
            	}
         	}
         	det += pow(-1.0,1.0+j1+1.0) * Matrix[0][j1] * detMatrix(m,size-1);
         	
			closeMatrix(m);
    	}
   }
   return det;
}










































