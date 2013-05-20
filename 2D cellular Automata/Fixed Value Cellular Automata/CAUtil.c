#include <stdio.h>
#include <stdlib.h>	
#include "Parameters.h"

void printrow (int PopArray[ArraySize][ArraySize])
	{
		int i;
		int j;		
		
		fflush(stdout);
		
	for( i= 0 ;  i< ArraySize; i++){
		for(j= 0 ;  j< ArraySize; j++){
			if (PopArray[i][j]==2){
		printf("1");
	}
	else if (PopArray[i][j]==1)
		printf("2");
	else
		printf(" ");
	}

	printf("\n");
	}
	}
/*
	void nextstate(int TempPop[ArraySize][ArraySize], int PopArray[ArraySize][ArraySize]){
		int x1, x2, x3 = {0};
		int y[3][3] = {0};
		for(int i= 0 ;  i< ArraySize; i++){
			if (i == 0){				//if right
				x1=ArraySize-1;
				x2=i;
				x3=i+1;
			}
			
			else if (i==ArraySize-1){		//if left
				x1 =	ArraySize - 2;
				x2 =	ArraySize - 1;
				x3 =	0;
			}

			else{						//else in middle
				x1 = i - 1;
				x2 = i;
				x3 = i + 1;
			}

			for(int j= 0 ;  j< ArraySize; j++){
							
				if (j == 0){						//if top
					y[0][0] = TempPop[x1][ArraySize - 1];
					y[0][1] = TempPop[x1][0];
					y[0][2] = TempPop[x1][1];
					y[1][0] = TempPop[x2][ArraySize - 1];
					y[1][1] = TempPop[x2][0];
					y[1][2] = TempPop[x2][1];
					y[2][0] = TempPop[x3][ArraySize - 1];
					y[2][1] = TempPop[x3][0];
					y[2][2] = TempPop[x3][1];
				} 

				else if (j==ArraySize-1){				//if bottom
					y[0][0] = TempPop[x1][ArraySize - 2];
					y[0][1] = TempPop[x1][ArraySize - 1];
					y[0][2] = TempPop[x1][0];
					y[1][0] = TempPop[x2][ArraySize - 2];
					y[1][1] = TempPop[x2][ArraySize - 1];
					y[1][2] = TempPop[x2][0];
					y[2][0] = TempPop[x3][ArraySize - 2];
					y[2][1] = TempPop[x3][ArraySize - 1];
					y[2][2] = TempPop[x3][0];
				}

				else{//if in middle
					y[0][0] = TempPop[x1][j - 1];
					y[0][1] = TempPop[x1][j];
					y[0][2] = TempPop[x1][j + 1];
					y[1][0] = TempPop[x2][j - 1];
					y[1][1] = TempPop[x2][j];
					y[1][2] = TempPop[x2][j + 1];
					y[2][0] = TempPop[x3][j - 1];
					y[2][1] = TempPop[x3][j];
					y[2][2] = TempPop[x3][j + 1];
				}

				int count = 0;
				for(int m = 0 ; m < 3; m++){
					for(int n = 0 ; n < 3 ; n++){
						if(!((m == 1) && (n ==1))){
						if (y[m][n]==1){
						PyCount++;
						}
						if (y[m][n]==1){
						PdCount++;
						}
						}
					}

			}
				if( y[1][1] == true){ //Cell is alive - referencing wrong array?
					if ((count == 2) || (count ==3)){
						PopArray[i][j] = true;
					}
					else
						PopArray[i][j] = false;
					}
				else {//cell is dead requires 2 parents (to provide new life)
					if (count == 3)
						PopArray[i][j] = true;
					}
	}
	}
	}
	*/