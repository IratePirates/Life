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


int main( void)
{

HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
CONSOLE_SCREEN_BUFFER_INFO bufferInfo;
GetConsoleScreenBufferInfo(h, &bufferInfo);

  FILE * pFile;
  pFile = fopen ("data.csv","w");

srand( (unsigned)time( NULL ) );
	int PopArray[ArraySize][ArraySize] =  {0};
	int TempPop[ArraySize][ArraySize] = {0};

//for( double i = 0.1 ; i < 2; i=i+0.1){
	//for( double j = 0.1 ; j < 2; j=j+0.1){
		//for( double k = 0.1 ; k < 2; k=k+0.1){
			//for( double l = 0.1 ; l < 2; l=l+0.1){	
int PYCount = 0;
int PDCount = 0;
int DeadCount = 0; 
	
	//Initialise Population 
	for(int i= 0 ;  i< ArraySize; i++){
	for(int j=0 ; j< ArraySize; j++){
		//PopArray[i][j] = 1;
		
		unsigned int Pyseed = (rand() % STARTPYPOP);
		unsigned int Pdseed = (rand() % STARTPDPOP);
		unsigned int Deadseed = (rand() % STARTDEAD);
	//	printf("%d ",(seed));		
		if (Pyseed < 1){
			PopArray[i][j] = 1;
			PYCount++;
		}
		else if (Pdseed <1){
			PopArray[i][j] = 2;
			PDCount++;
		}
	/*	else if (Deadseed <1){
			PopArray[i][j] = 8;
			DeadCount++;
		}*/
				else
			PopArray[i][j] = 0;
		}
	}
printf(" --- INITIAL GENERATION   --  Prey count %d, Pred Count %d, Dead Cell Count %d\n", PYCount, PDCount, DeadCount);	
	//SetConsoleCursorPosition(h, bufferInfo.dwCursorPosition);
printrow(PopArray);

					
					for (int CAGen = 0 ; CAGen < Life ; CAGen ++){
							//for each generation
						for(int m= 0 ;  m< ArraySize; m++){
							for(int n = 0; n<ArraySize; n++){
								TempPop[m][n] = PopArray[m][n];
							}
						}
									
						nextstate(TempPop, PopArray, 1, 1, 1, 1);
					//display result
					SetConsoleCursorPosition(h, bufferInfo.dwCursorPosition);
/*					
						PYCount = 0;
						PDCount = 0;

					for( int m = 0 ; m < WindowSize; m++){
						for( int n = 0 ; n < WindowSize; n++){
							if (PopArray[m][n] == 1){
								PYCount++;
							}
							else if (PopArray[m][n] == 2){
								PDCount++;
							}
						}
					}
					fprintf(pFile, "%d,%d,", PYCount, PDCount);

						PYCount = 0;
						PDCount = 0;

					for( int m = ArraySize - WindowSize ; m < ArraySize; m++){
						for( int n = 0 ; n < WindowSize; n++){
							if (PopArray[m][n] == 1){
								PYCount++;
							}
							else if (PopArray[m][n] == 2){
								PDCount++;
							}
						}
					}
					fprintf(pFile, "%d,%d,", PYCount, PDCount);

						PYCount = 0;
						PDCount = 0;

					for( int m = 0 ; m < WindowSize; m++){
						for( int n = ArraySize - WindowSize ; n < ArraySize; n++){
							if (PopArray[m][n] == 1){
								PYCount++;
							}
							else if (PopArray[m][n] == 2){
								PDCount++;
							}
						}
					}
					fprintf(pFile, "%d,%d,", PYCount, PDCount);

						PYCount = 0;
						PDCount = 0;

					for( int m = ArraySize - WindowSize ; m < ArraySize; m++){
						for( int n = ArraySize - WindowSize ; n < ArraySize; n++){
							if (PopArray[m][n] == 1){
								PYCount++;
							}
							else if (PopArray[m][n] == 2){
								PDCount++;
							}
						}
					}
					fprintf(pFile, "%d,%d", PYCount, PDCount);
*/
					PYCount = 0;
					PDCount = 0;
					
				for( int m = 0 ; m < ArraySize; m++){
						for( int n = 0 ; n < ArraySize; n++){
							if (PopArray[m][n] == 1){
								PYCount++;
							}
							else if (PopArray[m][n] == 2){
								PDCount++;
							}
						}
					}
					fprintf(pFile, "%d,%d\n", PYCount, PDCount);
					
					//if(CAGen>100){
					//printf("\n");
					printrow(PopArray);
					//}
 					printf(" ---  GENERATION - %d  -- Prey %d Pred %d \n", CAGen, PYCount, PDCount);
					
					
					
PYCount = 0;
PDCount = 0;
					for( int m = 0 ; m < ArraySize; m++){
						for( int n = 0 ; n < ArraySize; n++){
							if (PopArray[m][n] == 1){
								PYCount++;
							}
							else if (PopArray[m][n] == 2){
								PDCount++;
							}
						}
					}				
				}
					printrow(PopArray);
					printf(" --- FINAL GENERATION   --  Prey count %d, Pred Count %d\n", PYCount, PDCount);
				//}
			//}
		//}
	//}
fclose (pFile);

int wait = 0;
scanf("%d", &wait );

	return 0;

}
	
