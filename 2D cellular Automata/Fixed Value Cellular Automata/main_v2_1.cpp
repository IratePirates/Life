#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#include "CAUtils.h"
#include "Parameters.h"

/*************************
Pd Predators
Py Prey
*******************************/
//#define VS2008

int main( void)
{

HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
CONSOLE_SCREEN_BUFFER_INFO bufferInfo;
GetConsoleScreenBufferInfo(h, &bufferInfo);

#ifdef VS2008
  FILE * pFile;
  pFile = fopen ("data.csv","w");
#endif

srand( (unsigned)time( NULL ) );
int PopArray[ArraySize][ArraySize] =  {0};
int TempPop[ArraySize][ArraySize] = {0};

int PYCount = 0;
int PDCount = 0;
int DeadCount = 0; 
	
	//Initialise Population 
	for(int i= 0 ;  i< ArraySize; i++)
	{
	for(int j=0 ; j< ArraySize; j++)
		{
			unsigned int Pyseed = (rand() % STARTPYPOP);
			unsigned int Pdseed = (rand() % STARTPDPOP);
			unsigned int Deadseed = (rand() % STARTDEAD);
		//	printf("%d ",(seed));		
			if (Pyseed < 1)
			{
				PopArray[i][j] = 1;
				PYCount++;
			}
			else if (Pdseed <1)
			{
				PopArray[i][j] = 2;
				PDCount++;
			}
		/*	else if (Deadseed <1)
			{
				PopArray[i][j] = 8;
				DeadCount++;
			}*/
					else
			PopArray[i][j] = 0;
		}
	}
printf(" --- INITIAL GENERATION   --  Prey count %d, Pred Count %d, Dead Cell Count %d\n", PYCount, PDCount, DeadCount);	
printrow(PopArray);

					
		for (int CAGen = 0 ; CAGen < Life ; CAGen ++)
		{
				//for each generation
			for(int m= 0 ;  m< ArraySize; m++)
			{
				for(int n = 0; n<ArraySize; n++)
				{
					TempPop[m][n] = PopArray[m][n];
				}
			}
									
			nextstate(TempPop, PopArray, 1, 1, 1, 1);
			//display result
			SetConsoleCursorPosition(h, bufferInfo.dwCursorPosition);

			PYCount = 0;
			PDCount = 0;
					
	for( int m = 0 ; m < ArraySize; m++)
	{
			for( int n = 0 ; n < ArraySize; n++)
			{
				if (PopArray[m][n] == 1)
				{
					PYCount++;
				}
				else if (PopArray[m][n] == 2)
				{
					PDCount++;
				}
			}
		}
	
#ifdef VS2008
		fprintf(pFile, "%d,%d\n", PYCount, PDCount);
#endif				
					
		printrow(PopArray);
 		printf(" ---  GENERATION - %d  -- Prey %d Pred %d \n", CAGen, PYCount, PDCount);
				
		PYCount = 0;
		PDCount = 0;
		for( int m = 0 ; m < ArraySize; m++)
		{
			for( int n = 0 ; n < ArraySize; n++)
			{
				if (PopArray[m][n] == 1){
					PYCount++;
				}
				else if (PopArray[m][n] == 2)
				{
					PDCount++;
				}
			}
		}				
	}

	printrow(PopArray);
	printf(" --- FINAL GENERATION   --  Prey count %d, Pred Count %d\n", PYCount, PDCount);

#ifdef VS2008
fclose (pFile);

int wait = 0;
scanf("%d", &wait );
#endif	

return 0;
}
	
