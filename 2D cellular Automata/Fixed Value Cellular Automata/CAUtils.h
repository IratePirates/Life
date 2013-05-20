#include "Parameters.h"

#define _CRT_SECURE_NO_WARNING
#include <stdio.h>

void printrow (int PopArray[ArraySize][ArraySize]);
void nextstate(int TempPop[ArraySize][ArraySize], int PopArray[ArraySize][ArraySize], double K1, double K2, double K3, double K4);
void nextstate_Conway(int TempPop[ArraySize][ArraySize], int PopArray[ArraySize][ArraySize]);